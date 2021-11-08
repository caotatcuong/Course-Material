#ifndef _HEADER_H_
#define _HEADER_H_
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

void HoanVi(int& a, int& b);
void MergeSort(int* a, int l, int r);
void HeapSort(int* a, int n);
void CountingSort(int* input, int n);
void RadixSort(int* a, int n);
void flashsort(int *a, int n, int m);
void GenerateRandomData(int* a, int n);
void GenerateSortedData(int* a, int n);
void GenerateReverseData(int* a, int n);
void GenerateNearlySortedData(int* a, int n);
void Sort(int* a, int n, int i);
void Generate(int* a, int n, int i);
#endif