#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	for(int i = 0; i< 100; i++)
		printf("%d\t", rand()%100);
	
	printf("\n");
}
