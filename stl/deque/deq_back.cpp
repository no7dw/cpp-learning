#include "deque.h"
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
void printcontents(INTDEQUE deque);

int main(void)
{
	INTDEQUE dequetest;
	CourseItem CI1,CI2,CI3;
	CI1.ID="001";
	CI1.Name="Course1Name";
	CI1.Level=8;
	CI1.Path="\\tmp\\8\\001";
	CI2.ID="002";
	CI2.Name="Course2Name";
	CI2.Level=4;
	CI2.Path="\\tmp\\4\\002";
	CI3.ID="003";
	CI3.Name="Course3Name";
	CI3.Level=5;
	CI3.Path="\\tmp\\5\\003";

	dequetest.push_back(CI1);
	dequetest.push_back(CI2);
	dequetest.push_back(CI3);
		
	printcontents(dequetest);
	dequetest.pop_front();
	printcontents(dequetest);
	dequetest.pop_front();
	printcontents(dequetest);

}
void printcontents(INTDEQUE deque)
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
