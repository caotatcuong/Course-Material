#ifndef LISTSTUDENT_H_
#define LISTSTUDENT_H_
#include"Student.h"

class NODE
{
	Student* s;
	NODE* pNext;
	NODE();
	NODE(string, string, string, string, string);
	virtual~NODE();

	friend class ListStudent;

};

class ListStudent
{
public:
	NODE* pHead;
	NODE* pTail;
	static NODE* CreateNode(ifstream &f);
	void AddHead(NODE*);
	void AddTail(NODE*);
	void RemoveNode(string);
	ListStudent();
	~ListStudent();
	void ReadFile();
	void OutPutListStudent(NODE* p);
	void FindMaxScores();
	void ISortListStudent();
	void SSortListStudent();
	void QSortListStudent(ListStudent, int l, int r);
	void FindStudent();
	void HoanVi(NODE*, NODE*);
};

#endif