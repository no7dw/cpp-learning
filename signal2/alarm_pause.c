#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int ret=alarm(5);
	pause();
	printf("I have been waken up.\n",ret);//this line would not be execute.
}
