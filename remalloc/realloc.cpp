#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void)
{
	char *p;
	p=(char *)malloc(1024);
	cout << &p << endl;
	char *p2;
	p2=(char *)malloc(1000);	
	cout << &p2 << endl;
	p=(char*)realloc(p,2048);
	cout << &p << endl;
}
