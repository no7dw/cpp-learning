#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	const char*p1="a";
	
	const char*p2="正确答案:a";

	const char*p3="Answer:a";

	cout << "p1 = "<< p1 << endl;
	cout << "p2 = "<< p2 << endl;
	cout << "p3 = "<< p3 << endl;

	if( 0== strcmp(p1,p2))
		cout << "0== strcmp(p1,p2)" <<endl;
	else if( 0 < strcmp(p1,p2))
		cout << "0 < strcmp(p1,p2) " << strcmp(p1, p2 )<<endl;
	else if( 0 > strcmp(p1,p2))
		cout << "0 > strcmp(p1,p2) =" << strcmp(p1, p2) <<endl;
	

	if( 0== strcmp(p1,p3))
		cout << "0== strcmp(p1,p3)" <<endl;
	else if( 0 < strcmp(p1,p3))
		cout << "0 < strcmp(p1,p3) "<< strcmp(p1,p3) <<endl;
	else if( 0 > strcmp(p1,p3))
		cout << "0 > strcmp(p1,p3) =" << strcmp(p1, p3)<<endl;
}
