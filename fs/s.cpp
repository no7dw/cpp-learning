#include "f.h"
#include "s.h"
s::s()
{
	printf("%s \n", "儿子构造函数");
}

s::~s()
{
	printf("%s \n", "儿子析构函数");
}
/*
void s::fun()
{
	
	printf("%s \n", "儿子fun函数, call fun2()");
	printf("%s \t%s\t%s \n ", "儿子fun函数, call fun2()",this->su_name,this->last_name);
//	f::fun();
//	f::fun2();
	//fun2();
}

void s::fun2()
{
	pi();
	
	printf("%s \n", "儿子fun2函数");
}

void s::mi()
{
	this->istatic++;
}

void s::pi()
{
	printf("####%d#\n",this->istatic);
	
}
*/
void s::fun4()
{
	printf("%s \n", "儿子fun4函数");
	f::fun4();
}

void s::draw()
{
	printf("%s \n", "儿子draw函数");
}
