#ifndef NODE_H_
#define NODE_H_
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class NODE
{
public:
	string Data;
	bool Check;
	vector<NODE*> listdata;
	NODE();
	~NODE();
	NODE(string);
};

void DFS(NODE*);
#endif // !NODE_H_


