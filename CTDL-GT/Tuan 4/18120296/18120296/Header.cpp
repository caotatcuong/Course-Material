#include "Header.h"

void HoanVi(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void merge(int *a, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L, *R;
	L = new int[n1];
	R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
	delete[n1]L;
	delete[n2]R;
}

void MergeSort(int *a, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void heapify(int *a, int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = l;

	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		HoanVi(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void HeapSort(int *a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		HoanVi(a[0], a[i]);
		heapify(a, i, 0);
	}
}

void CountingSort(int *input, int n)
{
	int* output;
	output = new int[n];
	int max = input[0];
	int min = input[0];
	int i;
	for (i = 1; i < n; i++)
	{
		if (input[i] > max)
			max = input[i];
		else if (input[i] < min)
			min = input[i]; 
	}
	int k = max - min + 1; 
	int* count_array;
	count_array = new int[k];
	for (i = 0; i < k; i++)
		count_array[i] = 0;
	for (i = 0; i < n; i++)
		count_array[input[i] - min]++;
	for (i = 1; i < k; i++)
		count_array[i] += count_array[i - 1];
	for (i = 0; i < n; i++)
	{
		output[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}
	for (i = 0; i < n; i++)
		input[i] = output[i];
	delete[n]output;
	delete[k]count_array;
}

int getMax(int *a, int n)
{
	int mx = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > mx)
			mx = a[i];
	return mx;
}

void countSort(int *a, int n, int exp)
{
	int *output;
	output = new int[n];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		a[i] = output[i];
	delete[n]output;
}

void RadixSort(int *a, int n)
{
	int m = getMax(a, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp);
}

void GenerateRandomData(int* a, int n)// Hàm phát sinh mảng dữ liệu ngẫu nhiên
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

#include < stdio.h >
#include < math.h > ;
#include < stdlib.h > ;
const int THRESHOLD = 75;
const int CLASS_SIZE = 75;

void flashsort(int *a, int n, int m)
{
	int* l, nmin, nmax, i, j, k, nmove, nx, mx;
	float c1, c2, flash, hold;
	l = (int*)calloc(m, sizeof(int));
	nmin = nmax = 0;
	for (i = 0; i < n; i++)
		if (a[i] < a[nmin]) nmin = i;
		else if (a[i] > a[nmax]) nmax = i;
	if ((a[nmax] == a[nmin]))
	{
		return;
	}
	c1 = (m - 1.0) / (a[nmax] - a[nmin]);
	c2 = a[nmin];
	l[0] = -1;
	for (k = 1; k < m; k++) l[k] = 0;
	for (i = 0; i < n; i++)
	{
		k = floor(c1 * (a[i] - c2));
		l[k] += 1;
	}
	for (k = 1; k < m; k++) l[k] += l[k - 1];
	hold = a[nmax];
	a[nmax] = a[0];
	a[0] = hold;
	nmove = 0;
	j = 0;
	k = m - 1;
	while (nmove < n)
	{
		while (j > l[k])
		{
			j++;
			k = floor(c1 * (a[j] - c2));
		}
		flash = a[j];
		while (j <= l[k])
		{
			k = floor(c1 * (flash - c2));
			hold = a[l[k]];
			a[l[k]] = flash;
			l[k]--;
			flash = hold;
			nmove++;
		}
	}
	for (k = 0; k < (m - 1); k++)
	{
		if ((nx = l[k + 1] - l[k]) > THRESHOLD)
		{
			flashsort(&a[l[k] + 1], nx, CLASS_SIZE);
		}
		else
		{
			for (i = l[k + 1] - 1; i > l[k]; i--)
			{
				if (a[i] > a[i + 1])
				{
					hold = a[i];
					j = i;
					while (hold > a[j + 1])  a[j++] = a[j + 1];
					a[j] = hold;
				}
			}
		}
	}
	free(l);
}

void Sort(int* a, int n, int i)
{
	if (i == 0)
	{
		MergeSort(a, 0, n - 1);
	}
	if (i == 1)
	{
		HeapSort(a, n);
	}
	if (i == 2)
	{
		CountingSort(a, n);
	}
	if (i == 3)
	{
		RadixSort(a, n);
	}
	if (i == 4)
	{
		flashsort(a, n, 75);
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


