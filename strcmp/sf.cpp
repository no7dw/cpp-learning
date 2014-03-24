#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string p1="a";
	
	string p2="正确答案:a";

	string p3="Answer:a";

	cout << "p1 = "<< p1 << endl;
	cout << "p2 = "<< p2 << endl;
	cout << "p3 = "<< p3 << endl;
	
	cout<<"p2.find(p1) =" << p2.find(p1) <<endl;
	cout<<"p3.find(p1) =" <<p3.find(p1) << endl;
/*
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
*/
}
