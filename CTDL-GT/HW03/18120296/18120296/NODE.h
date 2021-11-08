#include"iostream"
using namespace std;

class NODE
{
public:
	int Data;
	NODE* Right;
	NODE* Left;
	NODE();
	NODE(int);
	~NODE();
};

void insertNode(NODE*& Root, int x);

void LNR(NODE* Root);

void Search(NODE* Root, int data);

void SearchStandFor(NODE*& p, NODE*& q);

int Remove(NODE*& Root, int data);

