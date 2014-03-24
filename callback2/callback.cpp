#include <stdio.h>
//#include <iostream>
//using namespace std;

typedef void (*CALLBACK)(int a,int b);

class Example
{
private:
	int m;
	int n;
	static CALLBACK func;
	public:
	void register_callback(CALLBACK fun,int k,int j);
	void callcallback();
	void calulate();
	void increase(int start,int stop);
	void decrease(int start,int stop);
};

CALLBACK Example::func=NULL;

void Example::register_callback(CALLBACK fun,int k,int j)
{
	func=fun;
	m=k;
	n=j;
}

void Example::callcallback()
{
	func(m,n);
}

void Example::increase(int start,int stop)
{
	for(int i= start; i< stop; i++)
		printf("increase i = %d\n", i);	
	
	callcallback();
}

void Example::decrease(int start,int stop)
{
	for(int i= start; i> stop; i--)
		printf("decrease i = %d\n", i);
	
	callcallback();
}
void Example::calulate()
{
	if(m<n)
		increase(m,n);
	else
		decrease(m,n);
}

void method_for_call(int a, int b)
{
	printf("\nsucceed finished the calulate work from %d to %d \n\n",a, b);
}

int main(void)
{
	Example ex;
	ex.register_callback(method_for_call,2,13);
	ex.calulate();
	printf("1------------ 1\n\n");	

	ex.register_callback(method_for_call,23,16);      
	ex.calulate();
	printf("2------------2\n\n");	
}

