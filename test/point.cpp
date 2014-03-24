#include <stdio.h>

int main(void)
{
	int *pint;
	if(!pint)
	{
		printf("pint is null\n");
	}

	char *pchar;
	if(!pchar)
	{
		printf("pchar is null\n");
	}

	char *pchar2=NULL;
	pchar2 = NULL;
	if(!pchar2)
	{
		printf("pchar2 is null\n");
	}
}
