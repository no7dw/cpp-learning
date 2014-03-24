#include<iostream> 
using namespace std; 

void func( int * &a, int b) 
{ 
	//for(int i=0;i<b;i++) 
	//	a[i]+=i; 
} 

int main() 
{ 
	const int test[10]={1,2,3,4,5,6,7,8,9,7}; 
	func(test,4); 
 
} 
