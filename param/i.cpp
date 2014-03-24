#include <stdio.h>

void func(const int *a, int size1,int size2)
{
	for(int i=0; i< size1;i++ )
	{
		for(int j=0; j < size2; j++ )
		{
			printf("%d\t",a[i*size2 + j]);
		}
		printf("\n");
	}
}
int main(void)
{
	int a[2][3]={{1,2,3}, {4,5,6}};
//	char *b = &a[0][0];
	func( &a[0][0], 2,3);
}
