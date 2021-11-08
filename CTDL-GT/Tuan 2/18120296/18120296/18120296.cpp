// 18120296.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ListStudent.h"

int main()
{
	ListStudent l;
	NODE* p;
	int n;
	do
	{
		cout << "----------------MENU---------------\n";
		cout << "0.Thoat\n";
		cout << "1. Doc file\n";
		cout << "2. Xuat danh sach hoc sinh\n";
		cout << "3. Xuat thong tin co diem cao nhat\n";
		cout << "4. Sap sep danh sach hoc sinh\n";
		cout << "5. Tim kiem thong tin hoc sinh theo diem\n";
		cout << "Nhap lua chon: ";
		cin >> n;
		if (n <= 5 && n >= 0)
		{
			switch (n)
			{
			case 0:
			{
				exit(0);
				break;
			}
			case 1:
			{
				l.ReadFile();
				break;
			}
			case 2:
			{
				p = l.pHead;
				l.OutPutListStudent(p);
				break;
			}
			case 3:
			{
				l.FindMaxScores();
				break;
			}
			case 4:
			{
				l.ISortListStudent();
				break;
			}
			default:
				break;
			}
		}
	} while (n <= 5 && n >= 0);
	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
