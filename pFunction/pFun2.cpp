#include <iostream>   
#include <string>   
using namespace std;   
   
int test(int);   
 
int test2(int (*ra)(int),int); 
 
int  main(int argc,char* argv[])     
{   
    cout<<test<<endl; 
    typedef int (*fp)(int);   
    fp fpi; 
    fpi=test;//fpi赋予test 函数的内存地址 
 
    cout<<test2(fpi,2)<<endl;//这里调用test2函数的时候,这里把fpi所存储的函数地址(test的函数地址)传递了给test2的第一个形参 
   
    return 1;
}   
   
int test(int a) 
{   
 //   return a-1; 
	cout << "do something after test2 done" <<endl;
	return 3;
} 
 
int test2(int (*ra)(int),int b)//这里定义了一个名字为ra的函数指针 
{ 
//    int c=ra(10)+b;//在调用之后,ra已经指向fpi所指向的函数地址即test函数 
//    return c;
	
	cout<< "in test2 do something about test2" << endl;
	ra(123);//now i am done ,do your work test
	return 1; 
} 
