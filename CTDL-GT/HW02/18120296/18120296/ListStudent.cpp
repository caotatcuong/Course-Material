#include "ListStudent.h"

NODE::NODE()
{
	this->pNext = NULL;
}

NODE::NODE(string a, string b, string c, float d)
{
	this->pNext = NULL;
	s = new Student(a, b, c, d);
}

NODE::~NODE()
{
}

NODE *ListStudent::getSV(int i)
{
	int dem = 0;
	for (NODE* p = pHead; p != pTail; p = p->pNext)
	{
		
		if (dem == i)
		{
			return p;
		}
		dem++;
	}

}

void ListStudent::HoanVi(NODE* p, NODE* q)
{
	Student* temp = q->s;
	q->s = p->s;
	p->s = temp;
}

NODE* ListStudent::CreateNode(ifstream& f)
{
	string a;
	getline(f, a, '\t');
	string b;
	getline(f, b, '\t');
	string c;
	getline(f, c, '\t');
	float d;
	f >> d;
	NODE* p = new NODE(a, b, c, d);
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

ListStudent::ListStudent()
{
	this->pHead = this->pTail = NULL;
}

ListStudent::~ListStudent()
{

}

void ListStudent::ReadFile()
{
	ifstream f;
	f.open("DanhSachSV.txt", ios::in);
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
		AddTail(p);
	}
	cout << "Da doc xong\n";
	f.close();
}

void ListStudent::OutPutListStudent()
{
	for (NODE* p = pHead; p != pTail; p = p->pNext)
	{
		cout << p->s->mMSSV << "\t" << p->s->mHo << "\t" << p->s->mTen << "\t" << p->s->get_mDiem() << endl;
	}
}

void ListStudent::BubleSort()
{
	int swapped;
	NODE* left;
	NODE* right = NULL;
	do
	{
		swapped = 0;
		left = pHead;
		while (left->pNext != right)
		{
			if (left->s->get_mDiem() > left->pNext->s->get_mDiem())
			{
				this->HoanVi(left, left->pNext);
				swapped = 1;
			}
			left = left->pNext;
		}
		right = left;

	} while (swapped);

}

NODE* ListStudent::Merge(NODE* h1, NODE* h2)
{
	NODE* t1 = new NODE;
	NODE* t2 = new NODE;
	NODE* temp = new NODE;
	if (h1 == NULL)
		return h2;
	if (h2 == NULL)
		return h1;
	t1 = h1;
	while (h2 != NULL)
	{
		t2 = h2;
		h2 = h2->pNext;
		t2->pNext = NULL;
		if (h1->s->get_mDiem() > t2->s->get_mDiem())
		{
			t2->pNext = h1;
			h1 = t2;
			t1 = h1;
			continue;
		}
	flag:
		if (t1->pNext == NULL)
		{
			t1->pNext = t2;
			t1 = t1->pNext;
		}
		else if ((t1->pNext)->s->get_mDiem() < t2->s->get_mDiem())
		{
			t1 = t1->pNext;
			goto flag;
		}
		else
		{
			temp = t1->pNext;
			t1->pNext = t2;
			t2->pNext = temp;
		}
	}
	return h1;
}

void ListStudent::MergeSort(NODE** head)
{
	NODE* first = new NODE;
	NODE* second = new NODE;
	NODE* temp = new NODE;
	first = *head;
	temp = *head;
	if (first == NULL || first->pNext == NULL)
		return;
	else
	{
		while (first->pNext != NULL)
		{
			first = first->pNext;
			if (first->pNext != NULL)
			{
				temp = temp->pNext;
				first = first->pNext;
			}
		}
		second = temp->pNext;
		temp->pNext = NULL;
		first = *head;
	}
	MergeSort(&first);
	MergeSort(&second);
	*head = Merge(first, second);
}

void ListStudent::QuickSort()
{
	ListStudent l1, l2;
	NODE* tag, * p;
	if (pHead == pTail) return;
	tag = pHead;
	pHead = tag->pNext; 

	while (pHead != NULL) {
		p = pHead;
		pHead = p->pNext;
		p->pNext = NULL;
		if (p->s->get_mDiem() <= tag->s->get_mDiem()) l1.AddTail(p);
		else l2.AddTail(p);
	}
	l1.QuickSort(); 
	l2.QuickSort();
	if (l1.pHead != NULL) 
	{ 
		pHead = l1.pHead; 
		l1.pTail->pNext = tag;
	} 
	else pHead = tag;
	tag->pNext = l2.pHead;
	if (l2.pHead != NULL) pTail = l2.pTail;
	else pTail = tag;
}

void ListStudent::RadixSort(int m)
{
	ListStudent B[10];
	NODE* p;
	int i, k;
	if (pHead == pTail)
	{
		return;
	}
	for (k = 0; k < m; k++)
	{
		while (pHead)
		{
			p = pHead;
			pHead = p->pNext;
			p->pNext = NULL;
			i = GetDigit(p->s->get_mDiem()*10, k);
			B[i].AddTail(p);
		}
		*this = B[0];
		for (i = 1; i < 10; i++)
		{
			AppendList(B[i]);
		}
	}
}

void ListStudent::AppendList(ListStudent& l1)
{
	if (pHead)
	{
		pTail->pNext = l1.pHead;
		pTail = l1.pTail;	
	}
	else
	{
		*this = l1;
	}
}

int ListStudent::GetDigit(long N, int k)
{
	switch (k)
	{
	case 0: return (N % 10);
	case 1: return ((N / 10) % 10);
	case 2: return ((N / 100) % 10);
	case 3: return ((N / 1000) % 10);
	case 4: return ((N / 10000) % 10);
	case 5: return ((N / 100000) % 10);
	case 6: return ((N / 1000000) % 10);
	case 7: return ((N / 10000000) % 10);
	case 8: return ((N / 100000000) % 10);
	case 9: return ((N / 1000000000) % 10);
	}

}

void ListStudent::SelectionSort()
{
	ListStudent result;
	NODE* min;
	NODE* p, * q, * minprev;
	while (pHead != NULL)
	{
		p = pHead;
		min = p;
		q = p->pNext;
		minprev = NULL;
		while (q != NULL)
		{
			if (q->s->get_mDiem() < min->s->get_mDiem())
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
}

void ListStudent::HeapSort(int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapify(n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		HoanVi(getSV(0), getSV(i));
		Heapify(i, 0);
	}
}

void ListStudent::Heapify(int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l<n && getSV(l)->s->get_mDiem()>getSV(largest)->s->get_mDiem())
	{
		largest = l;
	}
	if (r<n && getSV(r)->s->get_mDiem()>getSV(largest)->s->get_mDiem())
	{
		largest = r;
	}
	if (largest != i)
	{
		HoanVi(getSV(i), getSV(largest));
		Heapify(n, largest);
	}
}
