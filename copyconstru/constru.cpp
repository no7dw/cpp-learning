#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class Person{
	char *pName;
	public:
	Person(char *pN ="noName")
	{
		printf( "Constructing %s\n" ,pN );
		pName = new char (strlen(pN)+1);
		if(pName) 
			strcpy(pName, pN);
	}

	Person(const Person &s)
	{
		printf( "Constructing %s\n" ,s.pName );
		pName = new char (strlen(s.pName)+1);
		if(pName) 
			strcpy(pName, s.pName);
	}

	~Person()
	{
		printf("Destructing %s\n" , pName );
		delete[] pName;
	}
};

int main(void)
{
	Person p1("Randy");
	Person p2(p1);
}
