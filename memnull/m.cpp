#include <stdio.h>
#include <string.h>
#define SIZE 100
int main(void)
{
//char a[SIZE];
//char a[SIZE]={'1'};
char a[SIZE]={0};
int i=0;
for(i=0;i<SIZE;i++)
{
	if(a[i]!=NULL)
		printf("\t a[%d]= %c",i,a[i]);
	else
		printf("\t a[%d]= NULL",i);
}
printf("\n==============\n");

//memset(a,NULL, sizeof(char)*SIZE);
memset(a,0, sizeof(char)*SIZE);

int i2=0;
for(i2=0;i2<SIZE;i2++)
{
	if(a[i2]!=NULL)
		printf("\t a[%d]= %c",i2, a[i2]);
	else
		printf("\t a[%d]= NULL",i2);

}

}
