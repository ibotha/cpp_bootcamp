#include "Pony.hpp"

void ponyOnTheHeap()
{
	Pony *p = new Pony("Heapy");
	p->BeUsefull();
	delete p;
}

void ponyOnTheStack()
{
	Pony p("Stacky");
	p.BeUsefull();
}

int main()
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return 0;
}