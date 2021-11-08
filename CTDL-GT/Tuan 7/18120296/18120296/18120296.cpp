#include "NODE.h"

int main()
{
	NODE* a = new NODE("a"), *b = new NODE("b"), *c = new NODE("c"), *d = new NODE("d"), *e = new NODE("e"), *f = new NODE("f");
	a->listdata.push_back(b);
	a->listdata.push_back(d);
	a->listdata.push_back(f);
	b->listdata.push_back(a);
	b->listdata.push_back(c);
	b->listdata.push_back(d);
	c->listdata.push_back(b);
	c->listdata.push_back(d);
	d->listdata.push_back(a);
	d->listdata.push_back(b);
	d->listdata.push_back(c); 
	d->listdata.push_back(e);
	d->listdata.push_back(f);
	e->listdata.push_back(d);
	e->listdata.push_back(f);
	f->listdata.push_back(e);
	f->listdata.push_back(d);
	f->listdata.push_back(e);
	DFS(a);
	system("pause");
	return 0;
}
