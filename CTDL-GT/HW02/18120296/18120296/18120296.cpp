// 18120296.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ListStudent.h"

int main()
{
	ListStudent l;
	int n;
	do
	{
		cout << "Nhap lua chon: ";
		cin >> n;
		if (n <= 10 && n >= 0)
		{
			switch (n)
			{
			case 0:
			{
				l.OutPutListStudent();
				break;
			}
			case 1:
			{
				l.ReadFile();
				break;
			}
			case 2:
			{
				l.BubleSort();
				break;
			}
			case 3:
			{
				l.MergeSort(&l.pHead);
				break;
			}
			case 4:
			{
				l.QuickSort();
				break;
			}
			case 5:
			{
				l.SelectionSort();
				break;
			}
			case 6:
			{
				l.HeapSort(28);
				break;
			}
			case 7:
			{
				l.RadixSort(2);
				break;
			}
			}
		} 
	} while (n <= 7 && n >= 0);
	system("pause");
	return 0;
}

