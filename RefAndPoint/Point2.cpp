#include <iostream>
#include <cstdlib>
using namespace std;

void function(int **p)
{
	**p=100;
}

int main()
{
	int *x;
	x=(int *) malloc(4);
	*x=200;
	function(&x);
//	function(**x);
// invalid type argument of ‘unary *’
//	function(&&x);
// error too
//	function(*x);//*x is int type
// error: invalid conversion from ‘int’ to ‘int**’
// Point2.cpp:16: error:   initializing argument 1 of ‘void function(int**)’

	cout << "x ="<<*x<<endl;
	return 1;

}

