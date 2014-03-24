#include "newClass.h"

newCT::newCT()
{
//	(this.count)++;
	cout << "newCT() " << endl;
}
newCT::	~newCT()
{
	cout << "~newCT() Id "<< Id << endl;
}
void newCT::	Init(int id, string name)
{
	Id = id;
	Name = name;
}
void newCT::	printout()
{
	cout << "ID :" << Id << endl;
	cout << "Name :" << Name << endl;
}
void newCT::printcount()
{
	//cout << "count" <<   count << endl;
	cout << "count"  << endl;
}
