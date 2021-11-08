#include "NODE.h"

NODE::NODE()
{
	this->Right = NULL;
	this->Left = NULL;
}

NODE::NODE(int data)
{
	this->Right = NULL;
	this->Left = NULL;
	Data = data;
}

NODE::~NODE()
{
}

void insertNode(NODE*& Root, int x)
{
	if (Root)
	{
		if (Root->Data > x)
		{
			return insertNode(Root->Left, x);
		}
		else
		{
			return insertNode(Root->Right, x);
		}
	}
	Root = new NODE(x);


}

void LNR(NODE* Root)
{
	if (Root != NULL)
	{
		LNR(Root->Left);
		cout << Root->Data<<endl;
		LNR(Root->Right);
	}
}

void Search(NODE* Root, int data)
{
	if (Root != NULL)
	{
		Search(Root->Left,data);
		if (Root->Data == data)
		{
			cout << "Gia tri: " << Root->Data << "\tDia chi: " << &Root->Data<<endl;
		}
		Search(Root->Right,data);
	}
}

void SearchStandFor(NODE*& p, NODE*& q)
{
	if (q->Left)
		SearchStandFor(p, q->Left);
	else
	{
		p->Data = q->Data;
		p = q;
		q = q->Right;
	}
}

int Remove(NODE*& Root, int data)
{
	if (Root == NULL)
		return 0;
	if (Root->Data > data)
		return Remove(Root->Left, data);
	if (Root->Data < data)
		return Remove(Root->Right, data);
	else
	{
		NODE* p = Root;
		if (Root->Left == NULL)
			Root = Root->Right;
		else
		{
			if (Root->Right == NULL)
				Root = Root->Left;
			else
			{
				NODE* q = Root->Right;
				SearchStandFor(p, q);
			}
		}
		delete p;
	}
}


