#ifndef __DEQUE_
#define __DEQUE

#include <iostream>
#include <deque>
using namespace std;

typedef struct {
	string ID;
	string Name;
	int Level;
	string Path;
}CourseItem;

typedef deque<CourseItem> INTDEQUE;

class Deq
{
public:
	Deq();
	~Deq();
private:

	INTDEQUE QCI;
public:

	void printcontents(INTDEQUE &deque);

	void AddItem(CourseItem CI);
	int RemoveItem(string ID);
	void RemoveItem();
	
};
#endif
