#include <stdio.h>

void func(const char *a, int size1,int size2)
{
	for(int i=0; i< size1;i++ )
	{
		for(int j=0; j < size2; j++ )
		{
			printf("%c\t",a[i*size2 + j]);
		}
		printf("\n");
	}
}
int main(void)
{
	char a[2][3]={{'a','b','c'}, {'d','e','f'}};
	func( &a[0][0], 2,3);
}
