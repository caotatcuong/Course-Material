// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"


# define MaxFileLength 32
void IncreasePC()
{
	int counter = machine->ReadRegister(PCReg); //doc dia chi thanh ghi hien tai
   	machine->WriteRegister(PrevPCReg, counter); //ghi vao thanh ghi truoc 
    	counter = machine->ReadRegister(NextPCReg); // doc gia tri thanh ghi ke tiep
    	machine->WriteRegister(PCReg, counter); // ghi vao thanh ghi hien tai 
   	machine->WriteRegister(NextPCReg, counter + 4); //nap 4 byte cho thanh ghi ke tiep 
}

// Ham sao chep vung nho User sang vung nho System.
char* User2System(int virtAddr, int limit)
{
	int i; //chi so index
	int oneChar;
	char* kernelBuf = NULL;
	kernelBuf = new char[limit + 1]; //can cho chuoi terminal
	if (kernelBuf == NULL)
		return kernelBuf;
		
	memset(kernelBuf, 0, limit + 1);
	
	for (i = 0; i < limit; i++)
	{
		machine->ReadMem(virtAddr + i, 1, &oneChar);
		kernelBuf[i] = (char)oneChar;
		if (oneChar == 0)
			break;
	}
	return kernelBuf;
}

// Ham sao chep vung nho System sang vung nho User.
int System2User(int virtAddr, int len, char* buffer)
{
	if (len < 0) return -1;
	if (len == 0)return len;
	int i = 0;
	int oneChar = 0;
	do{
		oneChar = (int)buffer[i];
		machine->WriteMem(virtAddr + i, 1, oneChar);
		i++;
	} while (i < len && oneChar != 0);
	return i;
}


// Ham xu ly ngoai le
void ExceptionHandler(ExceptionType which)
{
    	int type = machine->ReadRegister(2);
	
	switch (which) {
	case NoException: //tra quyen cho hdh, khong xay ra loi
		return;

	case PageFaultException:{ // khong tim thay ban dich hop le 
		DEBUG('a', "\n No valid translation found"); // xuat thong bao o che do debug 
		printf("\n\n No valid translation found"); // xuat thong bao o che do run time 
		interrupt->Halt(); //dong hdh
		break;
	}
	case ReadOnlyException:{ //viet vao file duoc mac dinh chi doc 
		DEBUG('a', "\n Write attempted to page marked read-only");
		printf("\n\n Write attempted to page marked read-only");
		interrupt->Halt();
		break;
	}
	case BusErrorException:{ // ket qua duong dan den dia chi vat li khong hop le
		DEBUG('a', "\n Translation resulted invalid physical address");
		printf("\n\n Translation resulted invalid physical address");
		interrupt->Halt();
		break;
	}
	case AddressErrorException:{ // khong tham chieu den hoac vuot qua thanh dia chi 
		DEBUG('a', "\n Unaligned reference or one that was beyond the end of the address space");
		printf("\n\n Unaligned reference or one that was beyond the end of the address space");
		interrupt->Halt();
		break;
	}
	case OverflowException:{ // tran so trong phep cong hoac tru
		DEBUG('a', "\nInteger overflow in add or sub.");
		printf("\n\n Integer overflow in add or sub.");
		interrupt->Halt();
		break;
	}
	case IllegalInstrException:{ // chua cai dat hoac han che ve instr
		DEBUG('a', "\n Unimplemented or reserved instr.");
		printf("\n\n Unimplemented or reserved instr.");
		interrupt->Halt();
		break;
	}
	case NumExceptionTypes:{ //  ngoai le loai so
		DEBUG('a', "\n Number exception types");
		printf("\n\n Number exception types");
		interrupt->Halt();
		break;
	}
	case SyscallException:
		switch (type){

		case SC_Halt:{
			DEBUG('a', "\nShutdown, initiated by user program. ");
			printf("\nShutdown, initiated by user program. ");
			interrupt->Halt();
			return;
		}
		case SC_ReadInt:{
                    char* buffer;
                    int maxBuffer = 255; 
                    buffer = new char[maxBuffer + 1];
                    int numbytes = gSynchConsole->Read(buffer, maxBuffer);
                    int number = 0;
                    bool isNegative = false;
                    int firstPos = 0;
                    int lastPos = 0;
                    if(buffer[0] == '-') // Xu ly khi nhap so am.
                    {
                        isNegative = true;
                        firstPos = 1;
                        lastPos = 1;                        			   		
                    }
			
		    if (numbytes > 20) { // Vi C chi bieu dien duoc so co toi da 20 chu so nen neu nhap so qua lon thi bao loi va dung.
			printf("\n\nThe integer number is too big and it cannot be represented by C");
                        DEBUG('a', "\nThe integer number is too big and it cannot be represented by C");
			machine->WriteRegister(2, 0);
                        IncreasePC();
                        delete buffer;
                        return;
		    }
                                       
                    for(int i = firstPos; i < numbytes; i++)				
                    {
			if(buffer[i] < '0' || buffer[i] > '9') // Neu nhap vao ky tu khong phai so thi bao loi va dung.
                        {
                            printf("\n\nThe integer number is not valid");
                            DEBUG('a', "\nThe integer number is not valid");
                            machine->WriteRegister(2, 0);
                            IncreasePC();
                            delete buffer;
                            return;
                        }
                        lastPos = i;
                    }			
                    
                    // Chuyen chuoi ve so nguyen.
                    for(int i = firstPos; i<= lastPos; i++)
                    {
                        number = number * 10 + (int)(buffer[i] - 48);
                    }
			
                    if(isNegative) // Xu ly so am.
                    {
                        number = number * -1;
                    }
                    machine->WriteRegister(2, number);//tra gia tri number vao thanh ghi 2 
                    IncreasePC();
                    delete buffer;
                    return;
		}

		case SC_PrintInt:{
                    int number = machine->ReadRegister(4); // Doc so nguyen.
		    if(number == 0)
                    {
                        gSynchConsole->Write("0", 1); 
                        IncreasePC();
                        return;    
                    }
                    bool isNegative = false; 
                    int numLen = 0; 
                    int firstPos = 0; 
			
                    if(number < 0) // Xu ly so am.
                    {
                        isNegative = true;
                        number = number * -1; 
                        firstPos = 1; 
                    } 	
                    
                    int countNum = number; 
                    while(countNum) // Dem so chu so cua so nguyen.
                    {
                        numLen++;
                        countNum /= 10;
                    }
			
                    char* buffer;
                    int maxBuffer = 255;
                    buffer = new char[maxBuffer + 1];
		    // Chuyen so thanh chuoi ky tu de in.
                    for(int i = firstPos + numLen - 1; i >= firstPos; i--)
                    {
                        buffer[i] = (char)((number % 10) + 48);
                        number /= 10;
                    }
                    if(isNegative) // Xu ly so am.
                    {
                        buffer[0] = '-';
			buffer[numLen + 1] = 0;
                        gSynchConsole->Write(buffer, numLen + 1);
                        delete buffer;
                        IncreasePC();
                        return;
                    }
		    buffer[numLen] = 0;	
                    gSynchConsole->Write(buffer, numLen);
                    delete buffer;
                    IncreasePC();
                    return;		
		}

		case SC_ReadChar:{
			int maxBytes = 255; // Doc toi da 255 ky tu.
			char* buffer = new char[255];
			int numBytes = gSynchConsole->Read(buffer, maxBytes);

			if(numBytes > 1) // Khi nhap nhieu hon 1 ky tu thi bao loi va dung.
			{
				printf("Chi duoc nhap duy nhat 1 ky tu!");
				DEBUG('a', "\nERROR: Chi duoc nhap duy nhat 1 ky tu!");
				machine->WriteRegister(2, 0);
			}
			else if(numBytes == 0) // Nhap ky tu roi thi bao loi va dung.
			{
				printf("Ky tu rong!");
				DEBUG('a', "\nERROR: Ky tu rong!");
				machine->WriteRegister(2, 0);
			}
			else {				
				char c = buffer[0];
				machine->WriteRegister(2, c);
			}
			delete buffer;
			break;
		}

		case SC_PrintChar:{
			char c = (char)machine->ReadRegister(4); 
			gSynchConsole->Write(&c, 1);
			break;
		}
				
		case SC_ReadString:{
			int virtAddr, length;
			char* buffer;
			virtAddr = machine->ReadRegister(4);// doc dia chi tu thanh ghi 4
			length = machine->ReadRegister(5);// doc gia tri length tu thanh ghi 5 
			buffer = User2System(virtAddr, length);
			gSynchConsole->Read(buffer, length);
			System2User(virtAddr, length, buffer);// ghi chuoi buffer voi do dai length vao vung nho virtAddr dang giu
			delete buffer;
			IncreasePC();
			return;
		}
				
		case SC_PrintString:{
			int virtAddr;
			char* buffer;
			virtAddr = machine->ReadRegister(4);
			buffer = User2System(virtAddr, 255); // chuyen chuoi trong con tro virtAddr sang vung nho buffer
			int length = 0;
			while (buffer[length] != 0) length++;
			gSynchConsole->Write(buffer, length + 1);
			delete buffer;
			break;
		}

		case SC_Exec:
		{
			// Input: vi tri int
			// Output: Fail return -1, Success: return id cua thread dang chay
			// SpaceId Exec(char *name);
			int virtAddr;
			virtAddr = machine->ReadRegister(4);	// doc dia chi ten chuong trinh tu thanh ghi r4
			char* name;
			name = User2System(virtAddr, MaxFileLength + 1); // Lay ten chuong trinh, nap vao kernel
	
			if(name == NULL)
			{
				DEBUG('a', "\n Not enough memory in System");
				printf("\n Not enough memory in System");
				machine->WriteRegister(2, -1);
				//IncreasePC();
				return;
			}
			OpenFile *oFile = fileSystem->Open(name);
			if (oFile == NULL)
			{
				printf("\nExec:: Can't open this file.");
				machine->WriteRegister(2,-1);
				IncreasePC();
				return;
			}

			delete oFile;

			// Return child process id
			int id = pTab->ExecUpdate(name); 
			machine->WriteRegister(2,id);

			delete[] name;	
			IncreasePC();
			return;
		}

		case SC_Join:
		{       
			// int Join(SpaceId id)
			// Input: id dia chi cua thread
			// Output: 
			int id = machine->ReadRegister(4);
			
			int res = pTab->JoinUpdate(id);
			
			machine->WriteRegister(2, res);
			IncreasePC();
			return;
		}

		case SC_Exit:
		{
			//void Exit(int status);
			// Input: status code
			int exitStatus = machine->ReadRegister(4);

			if(exitStatus != 0)
			{
				IncreasePC();
				return;
				
			}			
			
			int res = pTab->ExitUpdate(exitStatus);
			//machine->WriteRegister(2, res);

			currentThread->FreeSpace();
			currentThread->Finish();
			IncreasePC();
			return; 
				
		}

		default:
			break;
		}
		IncreasePC();//tang program counter
	}
}
