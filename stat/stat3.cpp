#include <sys/types.h>  
#include <dirent.h>  
#include <stdio.h>  
#include <sys/stat.h>   

long FileSize = 0;

long CountFilesize(const char *path);

int main(int argc,char* argv[])  
{  
	CountFilesize(argv[1]);
}

long CountFilesize(const char *path)
{
	DIR *dp;  
	struct dirent * dirp;  
	if ((dp=opendir(path))==NULL)  
	{  
	printf("cant open %s",path);  
	return 0;  
	}  
	while((dirp=readdir(dp))!=NULL)  
	{ 
			 
		struct stat buf; 
		printf("dirp->d_name :%d\n", dirp->d_name); 
		if (lstat(dirp->d_name, &buf) < 0)  
		{  
		printf("lstat error");  
		}  
		if (S_ISDIR(buf.st_mode)) //是目录
		{  
		CountFilesize(dirp->d_name);
		}  
		else
		{
		int iresult;
		//iresult = _stat(__FILE__,&buf);
		iresult = stat(__FILE__,&buf);
		if(iresult == 0)
		{
		FileSize+= buf.st_size;
		}

		}
	}  
	closedir(dp);  
} 
