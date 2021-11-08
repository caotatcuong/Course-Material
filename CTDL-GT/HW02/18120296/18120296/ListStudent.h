#ifndef LISTSTUDENT_H_
#define LISTSTUDENT_H_
#include"Student.h"

class NODE
{
	Student* s;
	NODE* pNext;
	NODE();
	NODE(string, string, string, float);
	virtual~NODE();
	friend class ListStudent;
};

class ListStudent
{
public:
	NODE* pHead;
	NODE* pTail;
	static NODE* CreateNode(ifstream& f);
	void AddHead(NODE*);
	void AddTail(NODE*);
	ListStudent();
	~ListStudent();
	void ReadFile();
	void OutPutListStudent();

	void BubleSort();

	NODE* Merge(NODE* h1, NODE* h2);
	void MergeSort(NODE** head);

	void QuickSort();

	void RadixSort(int m);
	void AppendList(ListStudent&);
	int GetDigit(long, int);

	void SelectionSort();

	void Heapify(int n, int i);
	void HeapSort(int);
	
	NODE* getSV(int);
	void HoanVi(NODE*, NODE*);
};

#endif
