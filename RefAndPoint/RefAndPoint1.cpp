#include <iostream>
#include <cstdlib>

using namespace std;

//void function(int &*ref)
//cannot declare pointer to ‘int&’
void function(int *&ref)
{
	*ref = 100;
}

int main(void){

	int *x;
	x=(int *) malloc (4);
	*x=200;
	function(x);//ok
//	function(&x);
// error: invalid initialization of non-const reference of type ‘int*&’ from a temporary of type ‘int**’
// RefAndPoint1.cpp:8: error: in passing argument 1 of ‘void function(int*&)’

//	function(*x);
// error: invalid initialization of reference of type ‘int*&’ from expression of type ‘int’
// error: in passing argument 1 of ‘void function(int*&)’

//	function(&x);
//	 invalid initialization of non-const reference of type ‘int*&’ from a temporary of type ‘int**’
	cout<<"x = "<<*x<<endl;
	return 1;

}
