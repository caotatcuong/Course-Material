#include "Header.h"

void HoanVi(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void SelectionSort(int* a, int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min]) {
				min = j;
			}
		}
		HoanVi(a[min], a[i]);
	}
}

void InsertionSort(int* a, int n)
{
	int pos, i;
	int x;
	for (int  i = 1; i < n; i++)
	{
		x = a[i];
		pos = i - 1;
		while (pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

void ShellSort(int* a, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				a[j] = a[j - gap];
			a[j] = temp;
		}
	}
}

void BInsertionSort(int* a, int n)
{
	int l, r, m, i;
	int x;
	for (int  i = 1; i < n; i++)
	{
		x = a[i];
		l = 1;
		r = i - 1;
		while (l <= r) {
			m = (l + r) / 2;
			if (x < a[m]) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		for (int j = i - 1; j >= l; j--)
		{
			a[j + 1] = a[j];
		}
		a[l] = x;
	}
}

void BubbleSort(int* a, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				HoanVi(a[j], a[j - 1]);
			}
		}
	}
}

void ShakerSort(int* a, int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int j = Right; j > Left; j--)
		{
			if (a[j] < a[j - 1])
			{
				HoanVi(a[j], a[j - 1]);
				k = j;
			}
		}
		Left = k;
	}
}

void QuickSort(int* a, int l, int r)
{
	int i, j;
	int x;
	x = a[(l + r) / 2];
	i = l;
	j = r;
	do
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			HoanVi(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
	if (l < j)
		QuickSort(a, l, j);
	if (r > i)
		QuickSort(a, i, r);
}void GenerateRandomData(int* a, int n)// Hàm phát sinh mảng dữ liệu ngẫu nhiên
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
//
void GenerateSortedData(int* a, int n)// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
//
void GenerateReverseData(int* a, int n)// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
//
void GenerateNearlySortedData(int* a, int n)// Hàm phát sinh mảng dữ liệu gần như có thứ tự
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}
void Sort(int* a, int n, int i)
{
	if (i == 0)
	{
		SelectionSort(a, n);
	}
	if (i == 1)
	{
		InsertionSort(a, n);
	}
	if (i == 2)
	{
		ShellSort(a, n);
	}
	if (i == 3)
	{
		BInsertionSort(a, n);
	}
	if (i == 4)
	{
		BubbleSort(a, n);
	}
	if (i == 5)
	{
		ShakerSort(a, n);
	}
	if (i == 6)
	{
		QuickSort(a, 0, n-1);
	}
}

void Generate(int* a, int n, int i)
{
	if (i == 0)
	{
		GenerateRandomData(a, n);
	}
	if (i == 1)
	{
		GenerateSortedData(a, n);
	}
	if (i == 2)
	{
		GenerateReverseData(a, n);
	}
	if (i == 3)
	{
		GenerateNearlySortedData(a, n);
	}
}
