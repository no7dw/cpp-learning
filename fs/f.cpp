#include "f.h"
int f::istatic = 0;

f::f()
{
	printf("%s \n", "父亲构造函数");
	sprintf(su_name,"%s","deng");
	sprintf(mid_name,"%s","ju");
	sprintf(last_name,"%s","ping");
	istatic =1;
}
f::~f()
{
	printf("%s \n", "父亲析构函数");
}
// void f::fun()
// {
// 	
// 	printf("%s \n", "父亲fun函数, call virtual fun2()");
// 	//fun2();
// }
/*
void f::fun2()
{
	istatic =2;
	printf("%s \n", "父亲fun2函数");
}
void f::fun3()
{
	printf("%s \n", "父亲fun3函数");
}
*/
void f::fun4()
{
	printf("%s \n", "父亲fun4函数");
	draw();
}
void f::draw()
{
	printf("%s \n", "父亲draw函数");
}
