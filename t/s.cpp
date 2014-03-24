#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(void)
{

	if(strcmp("Soft_Update_Package_20110809.tar","Soft_Update_Package_20120103.tar")<0)
	{
		printf("<0\n");
	}
	else if(strcmp("Soft_Update_Package_20110809.tar","Soft_Update_Package_20120103.tar")>0)
	{
		printf(">0\n");
	}
	return 0;
}
