#include <cstdlib>  
#include <iostream>
using namespace std;

void function(int *ref)
{
	*ref=100;
}

int main(void){
/*
	int *x;
	x=(int *)malloc(4);
	*x=200;
	function(x);
	
	cout<< "*x = "<< *x <<endl ;
*/
	int x=200;
	function(&x);
	cout<< "x = "<< x <<endl ;
	return 1;
}

