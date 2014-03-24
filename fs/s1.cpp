#include "f.h"
#include "s1.h"
s1::s1()
{
	printf("%s \n", "儿子1构造函数");
}

s1::~s1()
{
	printf("%s \n", "儿子1析构函数");
}
void s1::fun()
{
	
	printf("%s \n", "儿子1fun函数, call fun2()");
	printf("%s \t%s\t%s \n ", "儿子1fun函数, call fun2()",this->su_name,this->last_name);
//	f::fun();
//	f::fun2();
	fun2();
}
void s1::fun2()
{
	pi();
	
	printf("%s \n", "儿子1fun2函数");
}
void s1::fun4()
{
	printf("%s \n", "儿子1fun4函数");
}
void s1::mi()
{
	this->istatic++;
}

void s1::pi()
{
	printf("####%d#\n",this->istatic);
	
}
