#include "stdio.h"
int main()
{
	#ifndef NDEBUG
	printf("starting main\n");
	#endif
	printf("something else\n");
}
