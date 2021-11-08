#ifndef _HEADER_H_
#define _HEADER_H_
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

void HoanVi(int& a, int& b);
void SelectionSort(int* a, int n);
void InsertionSort(int* a, int n);
void ShellSort(int* a, int n);
void BInsertionSort(int* a, int n);
void BubbleSort(int* a, int n);
void ShakerSort(int* a, int n);
void QuickSort(int* a, int l, int r);
void GenerateRandomData(int* a, int n);
void GenerateSortedData(int* a, int n);
void GenerateReverseData(int* a, int n);
void GenerateNearlySortedData(int* a, int n);
void Sort(int* a, int n, int i);
void Generate(int* a, int n, int i);
#endif

