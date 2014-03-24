#include "deq.h"

Deq::Deq()
{
}

Deq::~Deq()
{
}

void Deq::AddItem(CourseItem CI)
{
	QCI.push_back(CI);
		
}

void Deq::RemoveItem()
{
	QCI.pop_front();
}

int Deq::RemoveItem(string ID)
{
	QCI.pop_front();
}
		
void Deq::printcontents(INTDEQUE &deque)
{
	INTDEQUE::iterator pdeque;
	cout << "size = " << deque.size()<< endl;
	cout << "The output is:"<< endl;
	for(pdeque = deque.begin(); pdeque != deque.end(); pdeque++ )
	{
		cout << (*pdeque).ID << " ";
		cout << (*pdeque).Name << " ";
		cout << (*pdeque).Level << " ";
		cout << (*pdeque).Path << "   ";
	}
	cout << endl;
}
