#include <iostream>
using namespace std;

class Person
{
	char* pName;
public:
	Person(char* pN="noName")
	{
		cout<< "Constructing "<< pN << "\n";
		pName = new char(strlen(pN)+1);
		if(pName)
			strcpy(pName, pN);
	}
	
	Person(const Person &s)
	{
		cout<< "Copy Constructing "<< s.pName <<endl;
		pName=new char(strlen(s.pName)+1);
		if(pName) 
			strcpy(pName,s.pName);
	}
	
	~Person()
	{
		cout <<"Destructing "<<pName<<endl;
		delete[] pName;
	}
};

int main()
{
	Person p1("Randy");
	Person p2(p1);
}
