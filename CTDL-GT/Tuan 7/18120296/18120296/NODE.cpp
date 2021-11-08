#include "NODE.h"

NODE::NODE()
{
}

NODE::~NODE()
{
}

NODE::NODE(string data)
{
	this->Data = data;
	this->Check = false;
}

void DFS(NODE* p)
{
	p->Check = true;
	cout << p->Data << endl;
	for (int i = 0; i < p->listdata.size(); i++)
	{
		if (p->listdata[i]->Check == false)
		{
			DFS(p->listdata[i]);
		}
	}
}


