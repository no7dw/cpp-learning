#include <stdlib.h>
#include <stdio.h>
int add_n(int n)
{
	  static int i=100;
	    i+=n;
		  return i;
}
int main(int argc, char **argv)
{
	printf("%d\n",add_n(atoi(argv[1])));
	printf("%d\n",add_n(atoi(argv[2])));
}
