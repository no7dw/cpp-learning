#include <stdio.h>

int mer[14]={0};
void print_content(int *a, int size)
{
		for(int i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
}
void Merge(int *a,int *merge, int s, int m, int t)
{
	printf("[%d %d] [%d %d]\n",s,m,m+1,t);
/*
	printf("before\n");
	print_content(a,m-s+1);
	print_content(a,t-(m+1)+1);
*/
	int j,k;
	//a 分开[s,m] [m+1,t]两个有序部分
	for(j=m+1,k=s;s<=m&&j<=t;++k)//由小到大合并到merge中
	{
		if(a[s]<a[j])
			merge[k]=a[s++];
		else
			merge[k]=a[j++];
	}	
	if(s<=m)
		for(;s<=m&&k<=t;s++,k++)//合并剩余的a[s..m]
			merge[k]=a[s];
	if(j<=t)
		for(;j<=t&&k<=t;j++,k++)//合并剩余的a[j..t]
			merge[k]=a[j];
	printf("after:");
	//print_content(a,m-s+1);
	//print_content(a,t-(m+1)+1);
}
void MSort(int *a, int *b, int s, int t)
{
	if(s==t)
		b[s]=a[s];
	else
	{
		int mid = (s+t)/2;
		MSort(a,mer,s,mid);
		MSort(a,mer,mid+1,t);
		Merge(mer,b,s,mid,t);
	}
}

int main(void)
{

		int a[]={10,17,18,19,13,14,15,11,12,16,21,20,23,22};
		MSort(a,mer,0,sizeof(a)/sizeof(a[0]));//40/4
		print_content(mer,sizeof(mer)/sizeof(mer[0]));

//		MSort(a,a,0,sizeof(a)/sizeof(a[0]));//40/4
//		print_content(a,sizeof(a)/sizeof(a[0]));
		return 0;
}

