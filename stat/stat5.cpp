#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

//int fsize = 0;

void UTIL_CountFileSize(const char *dir, long &fsize)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	
	lstat(dir, &statbuf);
	if(! S_ISDIR(statbuf.st_mode))
	{
		fsize += statbuf.st_size;
		return ;
	}
	if((dp = opendir(dir)) == NULL)
	{
		fprintf(stderr ,"cannot open dirctory in UTIL_CountFileSize : %s \n", dir);
		return ;
	}
	//chdir(dir);
	while((entry = readdir(dp)) != NULL)
	{
		if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
		{
			continue;
		} 
		char dirname[255]={0};
		snprintf(dirname,255,"%s/%s",dir,entry->d_name);
		lstat(dirname, &statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			fsize += statbuf.st_size;
				//printf("DIR  %s\t%d\n",entry->d_name, statbuf.st_size);
			UTIL_CountFileSize(dirname, fsize);
		}
		fsize += statbuf.st_size;
		//printf("FILE  %s \t%d\n",entry->d_name, statbuf.st_size);
	}
	//chdir("..");//needed 
	closedir(dp);
}


int main(int argc , char **argv)
{

	long fsize = 0;
	if(argc>=2)
	{
		UTIL_CountFileSize(argv[1], fsize );	
		printf("fsize: %d \n",fsize);
		printf("fsize: %ld MB \n",fsize/1024/1024);
		printf("\ndone\n");
	}
	else
		printf("Useage: stat FolderPath\n");		
}
