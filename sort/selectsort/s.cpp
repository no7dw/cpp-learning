#include <stdio.h>
int SelectMinKey(int *a,int ibound)
{
	int min= a[ibound];
	for(int i=ibound+1;i<sizeof(a)/sizeof(a[0]);i++)
	{
		if(min>a[i])
			min=a[i];
	}
	return min;
}

void SelectSort(int *a, int size)
{
	int tempi;
	for(int i=1;i<size;i++)
	{
		int j = SelectMinKey(a,i);
		if(i!=j)
		{
			tempi = a[i];
			a[i]=a[j];
			a[j]=tempi;
		}
	}
}
//输出内容
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
	int a[]={0,7,8,9,3,4,5,1,2,6,11,10,13,12};
	SelectSort(a,sizeof(a)/sizeof(a[0]));//40/4
	print_content(a,sizeof(a)/sizeof(a[0]));
	return 0;
}

