#include <stdio.h>
int main(void)
{
	int a =10;
	int b = 12*a++;
	printf("b = %d a= %d \n", b, a);
	int c = 12*++a;
	printf("c = %d a= %d \n", c, a);
	return 0;
}
