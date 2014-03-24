#include <sys/stat.h>
#include <stdio.h>

int main(int argc , char **argv)
{
	struct stat buf;
	int istatus;
	if(argc>=2)
	{
		istatus = stat(argv[1] , &buf);
		printf("size: %ld \n",buf.st_size );
		return 0;
	}
	else 
		return -1;
	
}
