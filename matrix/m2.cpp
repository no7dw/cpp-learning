#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
//	char **p;
	char *p[3];
	for(int i=0;i<3;i++)
	{
		p[i]= new char[200];
		memset(p[i],'a',200);
	}

	for(int i=0;i<3;i++)
	{
		delete []p[i];
		p[i] = NULL;
	}
	if(p==NULL)
		printf("p is null\n");
	else
	{
		printf("p is not  null\n");
		printf("p is :%s\n", p);
		printf("*p is :%s\n", *p);
		printf("p[0] is :%s\n", p[0]);
		printf("p[1] is :%s\n", p[1]);
	}
//	delete []p;//senal falt
}
