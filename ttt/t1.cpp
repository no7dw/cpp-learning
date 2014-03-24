#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	//if(strncmp("99",argv[1],2) ==0)
	if(strncmp(argv[1],"99" , 2) ==0)
		printf("99 true\n");
	else
		printf("false\n");
}
