#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mall(char *pbuf)
{
	memset(pbuf, 'a', 100);
}
int main(void)
{
	char *ps1;
	ps1 = (char *)malloc(100);
	printf("before: ps1 = %s\n",ps1);
	mall(ps1);
	printf("after: ps1 = %s\n",ps1);
	return 0;
}
