#include <stdio.h>
int main(int argc, char **argv)
{
	FILE *plog = fopen(argv[1],"ab");
	if(plog)
	{
		fprintf(plog ,"[%s]\n",argv[2]);
		fflush(plog);
		fclose(plog);
	}

	return 0;
}
