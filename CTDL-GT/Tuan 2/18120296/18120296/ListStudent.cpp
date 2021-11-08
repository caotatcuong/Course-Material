#include "ListStudent.h"

NODE::NODE()
{
	this->pNext = NULL;
}

NODE::NODE(string a, string b, string c, string d, string e)
{
	this->pNext = NULL;
	s = new Student(a, b, c, d, e);
}

NODE::~NODE()
{
}

void ListStudent::HoanVi(NODE*p, NODE* q)
{
	NODE* temp = q->pNext;
	q->pNext = p;
	p->pNext = temp;
}

NODE* ListStudent::CreateNode(ifstream &f)
{
	string a;
	getline(f, a, '\t');
	string b;
	getline(f, b, '\t');
	string c;
	getline(f, c, '\t');
	string d;
	getline(f, d, '\t');
	string e;
	getline(f, e, '\n');
	NODE* p = new NODE(a, b, c, d, e);
	p->pNext = NULL;
	return p;
}

void ListStudent::AddHead(NODE* p)
{
	if (pHead == NULL && pTail == NULL)
	{
		this->pHead = p;
		this->pTail = p;
	}
	else
	{
		p->pNext = this->pHead;
		pHead = p;
	}
}

void ListStudent::AddTail(NODE* p)
{
	if (pHead == NULL && pTail == NULL)
	{
		this->pHead = p;
		this->pTail = p;
	}
	else
	{
		this->pTail->pNext = p;
		pTail = p;
	}
}

void ListStudent::RemoveNode(string k)
{
	NODE* p = pHead;
	NODE* q = NULL;
	while (p != NULL)
	{
		if (p->s->get_mScores() == k)
		{
			break;
		}
		q = p;
		p = p->pNext;
	}
	if (p == NULL)return;
	if (q != NULL)
	{
		if (p == pTail)
		{
			pTail = q;
		}
		q->pNext = p->pNext;
		delete p;
	}
	else
	{
		pHead = p->pNext;
		if (pHead == NULL)
		{
			pTail == NULL;
		}
	}
	return;
}

ListStudent::ListStudent()
{
	this->pHead = this->pTail = NULL;
}

ListStudent::~ListStudent()
{
	while (pHead != NULL)
	{
		NODE* p = pHead;
		pHead = pHead->pNext;
		delete p;
	}
}

void ListStudent::ReadFile()
{
	ifstream f;
	f.open("DiemSV.txt", ios::in);
	if (!f)
	{
		cout << "Khong mo duoc file";
		return;
	}
	while (!f.eof())
	{
		ListStudent liststudent;
		NODE* p = new NODE();
		p = liststudent.CreateNode(f);
		AddHead(p);
	}
	cout << "Da doc xong\n";
	f.close();
}

void ListStudent::OutPutListStudent(NODE* p)
{
	cout << p->s->mId << "\t" << p->s->mSurname << "\t" << p->s->mName << "\t" << p->s->get_mDate_of_birth() << "\t" << p->s->get_mScores() << endl;
	p = p->pNext;
	if (p == NULL)
	{
		return;
	}
	OutPutListStudent(p);
}

void ListStudent::FindMaxScores()
{
	NODE* p = this->pHead;
	string max = p->s->get_mScores();
	for (; p != NULL; p = p->pNext)
	{
		if (p->s->get_mScores() > max)
		{
			max = p->s->get_mScores();
		}
	}
	fstream f;
	f.open("MaxDiem.txt", ios::out);
	if (!f)
	{
		cout << "Khong mo duoc file";
		system("pause");
	}
	for (NODE* q = this->pHead; q != NULL; q = q->pNext)
	{
		if (q->s->get_mScores() == max)
		{
			f << q->s->mId << "\t" << q->s->mSurname << "\t" << q->s->mName << "\t" << q->s->get_mDate_of_birth() << "\t" << q->s->get_mScores() << endl;
		}
	}
	cout << "Da ghi vao file MaxDiem.txt\n";
	f.close();
}

void ListStudent::ISortListStudent()
{
	NODE* p = pHead->pNext, * q = pHead;
	HoanVi(q,p);
	NODE* k = pHead;
	cout << "\nDanh sach sinh vien sau khi sap xep tang dan theo diem la: \n";
	OutPutListStudent(k);
}


void ListStudent::SSortListStudent()
{
	ListStudent result;
	NODE* min;
	NODE* p, * q, *minprev;
	while (pHead != NULL)
	{
		p = pHead;
		min = p;
		q = p->pNext;
		minprev = NULL;
		while (q != NULL)
		{
			if (q->s->get_mScores() < min->s->get_mScores())
			{
				min = q;
				minprev = p;
			}
			p = q;
			q = q->pNext;
		}
		if (minprev != NULL)
		{
			minprev->pNext = min->pNext;
		}
		else
		{
			pHead = min->pNext;
		}
		min->pNext = NULL;
		result.AddTail(min);
	}
	*this = result;
	
	NODE* k = this->pHead;
	cout << "\nDanh sach sinh vien sau khi sap xep tang dan theo diem la: \n";
	OutPutListStudent(k);
	result.~ListStudent();
}






