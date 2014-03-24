#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

//int fsize = 0;

void CountFileSize(const char *dir, int &fsize)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	
	if((dp = opendir(dir)) == NULL)
	{
		fprintf(stderr ,"cannot open dirctory : %s \n", dir);
		return ;
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
			{
				continue;
			}
			else
			{
				fsize += statbuf.st_size;
				printf("DIR  %s\t%d\n",entry->d_name, statbuf.st_size);
				CountFileSize(entry->d_name, fsize);
			}
		}
		fsize += statbuf.st_size;
		printf("FILE  %s \t%d\n",entry->d_name, statbuf.st_size);
		
	}
	chdir("..");//needed 
	closedir(dp);
}

int main(int argc , char **argv)
{

	int fsize = 0;
	if(argc>=2)
	{
		CountFileSize(argv[1], fsize );	
		printf("fsize: %d \n",fsize);
		printf("fsize: %ld MB \n",fsize/1024/1024);
		printf("\ndone\n");
	}
	else
		printf("Useage: stat FolderPath\n");		
}
