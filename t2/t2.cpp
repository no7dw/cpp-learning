#include<iostream> 
#include <stdio.h>
using namespace std; 

void func(int * &a, int b) 
{
   printf("a (*a) adress  is : %x \n", *a);	
   cout << "a[0] &(*a) address is " << &(*a) << endl;
   cout << "a a is " << a << endl;
   cout<< " a (&a)is point to: "<<  &a << endl;	
	for(int i=0;i<b;i++) 
		a[i]+=i; 
} 

int main() 
{ 
	int test[10]={1,2,3,4,5,6,7,8,9,10}; 
	cout << "test address "<< test << endl;
	int *temp = test;
	func(temp,4); 
	cout<<"After assignment, test is "<<endl; 
	for(int i =0;i<10;i++) 
		printf("%d\t",test[i]);
	printf("\n");
} 
