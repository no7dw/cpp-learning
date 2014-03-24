#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

bool UTIL_CheckFile( const char *szFile )
{
	// check if file exists

	FILE *pFile = NULL;

	if( ( pFile = fopen( szFile, "r" ) ) == NULL )
		return false;

	fclose( pFile );

	return true;
}

void UTIL_MakeFile( const char *szFile, string strContents )
{
	FILE *pFile = NULL;

	if( ( pFile = fopen( szFile, "wb" ) ) == NULL )
	{
		//UTIL_LogPrint( "warning - unable to open %s for writing\n", szFile );

		return;
	}

	fwrite( (void *)strContents.c_str( ), sizeof( char ), strContents.size( ), pFile );
	fclose( pFile );
}


string UTIL_ReadFile( const char *szFile )
{
	FILE *pFile = NULL;

	if( ( pFile = fopen( szFile, "rb" ) ) == NULL )
	{
//		UTIL_LogPrint( "warning - unable to open %s for reading\n", szFile );

		return string( );
	}
//	UTIL_LogPrint( "open %s for reading\n", szFile );

	fseek( pFile, 0, SEEK_END );
	unsigned long ulFileSize = ftell( pFile );
	fseek( pFile, 0, SEEK_SET );
	char *pData = (char *)malloc( sizeof( char ) * ulFileSize );
	memset( pData, 0, sizeof( char ) * ulFileSize );
	fread( (void *)pData, sizeof( char ), ulFileSize, pFile );
	fclose( pFile );
	string strFile( pData, ulFileSize );
	free( pData );

	return strFile;
}

void UTIL_CopyFile( const char *szFile, const char *szDest  )
{
	if( UTIL_CheckFile( szDest )  )
	{
		//UTIL_LogPrint( "error archiving \"%s\" - destination file already exists\n", szDest );
	}
	else

		UTIL_MakeFile( szDest, UTIL_ReadFile( szFile )  );

}

/*
void CP(const char *SrcDir,const char *TargetDir )
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	mkdir(TargetDir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	if((dp = opendir(SrcDir)) == NULL)
	{
		fprintf(stderr ,"cannot open dirctory : %s \n", SrcDir);
		return ;
	}
	chdir(SrcDir);
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
				//new a dir
				mkdir(entry->d_name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
				//then loop
				char SubTargetDir[260]={0};
				char SubSrcDir[260]={0};

				sprintf(SubSrcDir,"%s/%s",SrcDir,entry->d_name );
				sprintf(SubTargetDir,"%s/%s",TargetDir,entry->d_name );
				printf("%s\t%s\n", SubSrcDir, SubTargetDir );
				CP(SubSrcDir,SubTargetDir );
			}
		}
		//copy file
		char SubSrcFile[260]={0};
		sprintf(SubSrcFile ,"%s/%s",SrcDir,entry->d_name );
		char SubTargetFile[260]={0};
		sprintf(SubTargetFile,"%s/%s",TargetDir,entry->d_name );

		UTIL_CopyFile(SubSrcFile,SubTargetFile );
		
	}
	chdir("..");//needed 
	closedir(dp);
}
*/
void UTIL_CopyDir(const char *SrcDir,const char *TargetDir )
{	

	//UTIL_Debug_Print(__FILE__,__LINE__,__func__,"\n\n\n\n\n");	
	printf("copy dir : %s -> %s \n" , SrcDir, TargetDir);
	
	//return ;//2011-8-24
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	
	if((dp = opendir(SrcDir)) == NULL)
	{
		fprintf(stderr ,"cannot open dirctory : %s \n", SrcDir);
		return ;
	}
	if((dp = opendir(TargetDir)) == NULL)
	{
		mkdir(TargetDir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);//八进制600表示同样的权限
	}
	chdir(SrcDir);
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
				//new a dir
				//mkdir(entry->d_name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
				//then loop
				char SubTargetDir[260]={0};
				char SubSrcDir[260]={0};

				sprintf(SubSrcDir,"%s/%s",SrcDir,entry->d_name );
				sprintf(SubTargetDir,"%s/%s",TargetDir,entry->d_name );
				printf("%s\t%s\n", SubSrcDir, SubTargetDir );
				UTIL_CopyDir(SubSrcDir,SubTargetDir );
			}
		}
		//copy file
		char SubSrcFile[260]={0};
		sprintf(SubSrcFile ,"%s/%s",SrcDir,entry->d_name );
		char SubTargetFile[260]={0};
		sprintf(SubTargetFile,"%s/%s",TargetDir,entry->d_name );

		UTIL_CopyFile(SubSrcFile,SubTargetFile );
		
	}
	chdir("..");//needed 
	closedir(dp);
}
int main(int argc , char **argv)
{
	if(argc>=2)
	{
		//CP(argv[1], argv[2] );
		UTIL_CopyDir(argv[1], argv[2] );
		printf("\ndone\n");
	}
	else
		printf("Useage: stat FolderPath\n");		
}
