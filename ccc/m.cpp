#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	//char a[10] = "12345";
	char a[10] = {0};
	strcpy(a,"12345");

	char b1 = a[0];
	/*
	printf("a[0] = %c\n", a[0]);
	printf("b1 = %c\n", b1);
	printf("b1 address = %x\n" ,&b1 );
	printf("a[0] address = %x\n" ,&a[0] );
	printf("a address = %x\n" , &a );
	*/
//	int a1 = atoi(&b1);
	int a1= b1 - '0';
	printf("a1 = %d\n", a1);


	char cb1[2]={0};
	cb1[0] =a[0];
	int ib11 = atoi(cb1);
	printf("ib11 = %d\n", ib11);
}
