#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

struct cs1{
int id;
string content;
string title;
};

struct cs2{
int id;
string content;
string title;
};

struct cs3{
int id;
string content;
};

struct myStruct{
double dda1;
char cda;
int type;
};

struct myStruct2{
char cda;
double dda1;
int type;
};
int main(void)
{
	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(double) = %d\n", sizeof(double));
	printf("sizeof(float) = %d\n", sizeof(float));
	printf("sizeof(long) = %d\n", sizeof(long));
	printf("sizeof(string) = %d\n", sizeof(string));
	printf("sizeof(char) = %d\n", sizeof(char));
	cs1 c1 ;
	c1.id=0;
	c1.content="1234567890";
	c1.title ="123";
	cs2 c2;
	c2.id=12345;
	c2.content="1234567890123456789012345678901234567890";
	c2.title ="123456789012345678901234567890";
	
	cs3 c3;
	c3.id=1234567;
	c3.content=string(100,'a');

	printf("sizeof(cs1) %d\n", sizeof(cs1));
	printf("sizeof(cs2) %d\n", sizeof(cs2));
	printf("sizeof(cs3) %d\n", sizeof(cs3));
	
	printf("sizeof(c1) %d\n", sizeof(c1));
	printf("sizeof(c2) %d\n", sizeof(c2));
	printf("sizeof(c3) %d\n", sizeof(c3));

	printf("sizeof(myStruct) = %d\n" ,sizeof(myStruct));
	printf("sizeof(myStruct2) = %d\n" ,sizeof(myStruct2));
}
