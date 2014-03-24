#include <stdio.h>
#include <iostream>
#include <dirent.h>
#include <string.h>
int main(int argc , char** argv)
{
	DIR *dp;
	struct dirent *dirp;
	if(argc!=2)
	{
		printf("Usage: ls directory_name");
		return 0;
	}
	if((dp=opendir(argv[1]))==NULL)
	{
		printf("can't open %s", argv[1]);
		return 0;
	}
	while((dirp = readdir(dp))!=NULL)
	{
		if(strcmp(dirp->d_name , ".") != 0 and strcmp(dirp->d_name, "..")!=0 )
		printf("%s\t", dirp->d_name);
	}
	
	printf("\n");
	closedir(dp);
	return 1;		
}
