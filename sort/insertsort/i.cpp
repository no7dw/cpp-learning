#include <stdio.h>

void InsertSort(int *a, int size)
{
	int temp,j;
	for(int start=1;start<size;start++)
	{
		temp = a[start];
		for(j = start;j>0&&(temp < a[j-1]);j--)
		{
			a[j] = a[j-1];
			
		}
		a[j]=temp;

		
	}
}

void print_content(int *a, int size)
{
		for(int i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
}
int main(void)
{

		int a[]={10,17,18,19,13,14,15,11,12,16,21,20,23,22};
		InsertSort(a,sizeof(a)/sizeof(a[0]));
		print_content(a,sizeof(a)/sizeof(a[0]));

		return 0;
}

