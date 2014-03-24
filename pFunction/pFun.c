//#include <iostream>
//using namespace std;

typedef void (*pfv)(int);
void func(int index)
{
	printf( "now in func when something finished . this func will be called\n");
	printf("index  = %d\n",index);
}

void caller(void(*ptr)(int),int index,int para)
{
	printf( "now in caller doing something\n");
	printf( "caller done\n");
	ptr(index);//this will call function which ptr points to
}

int  main()
{
	pfv p= func;
	caller(p, 1 , 2);
}
