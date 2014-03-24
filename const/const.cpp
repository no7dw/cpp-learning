#include <iostream>
using namespace std;
int main()
{
	//const char *p;
	//char const *p;
	//char * const p;//error uninitalize
//	char * const p='a';// invalid conversion from ‘char’ to ‘char*’ ;p read-only
	char a='a'; char b='b';
	
	const char * const p=&a;
//	*p=&b;//p read-only, //assignment of read-only location ‘*(const char*)p’ when const char * const p=&a;
//	p="abc";//error when const char * const p=&a;
//	p="bcd";//error when const char * const p=&a;
//	p=&a;//error when const char * const p=&a;
//	p=&b;//error when const char * const p=&a;
//	*p=&a;//error when const char *p //assignment of read-only location ‘* p’
	//char const *p; //assignment of read-only location     ‘* p’
	

	cout << p << endl;
}
