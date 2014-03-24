#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
int  splitString(const string & strSrc, const std::string& strDelims, vector<string>& strDest)  
{  
        typedef std::string::size_type ST;  
        string delims = strDelims;  
        std::string STR;  
        if(delims.empty()) 
                        delims = "\n\r";  
    
        ST pos=0, LEN = strSrc.size();  
        while(pos < LEN )
                {   
            STR="";   
            while( (delims.find(strSrc[pos]) != std::string::npos) && (pos < LEN) ) 
                                ++pos;  
            if(pos==LEN) 
                                return strDest.size();  
            while( (delims.find(strSrc[pos]) == std::string::npos) && (pos < LEN) ) 
                                STR += strSrc[pos++];  
            //std::cout << "[" << STR << "]";  
            if( ! STR.empty() ) 
                                strDest.push_back(STR);
        }   
        return strDest.size();  
} 
string UTIL_ReadFile( const char *szFile )
{
        FILE *pFile = NULL;

        if( ( pFile = fopen( szFile, "rb" ) ) == NULL )
        {
		printf("file %s not exist!\n", szFile);
                return string( );
        }

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

bool UTIL_CheckFile( const char *szFile )
{
        // check if file exists
        FILE *pFile = NULL;
        if( ( pFile = fopen( szFile, "r" ) ) == NULL )
                return false;
        fclose( pFile );
        return true;
}

int checkReadorder(const char *path)
{
	vector<string> v_words	;
	string strFileContent = UTIL_ReadFile(path);
	//printf("path : %s \t strFileContent: %s\n", path , strFileContent.c_str());
	splitString(strFileContent, "#", v_words);	
	
	char file_full_path[255] = {0};
	const char* filetype=".avi";
	//printf("size: %d\n", v_words.size());
	char temp_full_dir_path[255] = {0};
	memset(temp_full_dir_path, 0, sizeof(temp_full_dir_path));
	snprintf(temp_full_dir_path, strlen(path)-strlen("ReadOrder.txt"), "%s", path);

	for(int  i = 0; i< v_words.size(); i++)	
	{
/*	
		if(strlen(v_words[i].c_str()) == 0)
			continue;
		if(strlen(v_words[i].c_str()) == 1)
			printf("[1]:%d\n", v_words[i].c_str()[0]);
		printf("len %d %s\n",strlen(v_words[i].c_str()), v_words[i].c_str());

		if(strcmp(v_words[i].c_str(), " ") == 0)
			printf("it is a space\n");
			*/
		if(strlen(v_words[i].c_str()) == 1)
			continue;
		memset(file_full_path, 0, sizeof(file_full_path)); 
		sprintf(file_full_path,"%s/%s%s", temp_full_dir_path, v_words[i].c_str()+1 ,filetype);
		//printf("%s\n", file_full_path);
		if(!UTIL_CheckFile(file_full_path))
			printf("WARNING: %s NOT exist!\n", file_full_path);
	}

}

void printdir(const char *dir, int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp=opendir(dir)) == NULL)
	{
		fprintf(stderr, "cannot open directory : %s\n", dir);
		return;
	}
	chdir(dir);
	while((entry=readdir(dp)) !=NULL )
	{
		lstat(entry->d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			if( (strcmp(".", entry->d_name) == 0) ||(strcmp("..", entry->d_name) == 0) )
			{
				continue;
			}
			//printf("%*s%s/\n", depth, "", entry->d_name);
			char temp_full_path[255] = {0}; 
			memset(temp_full_path, 0, sizeof(temp_full_path));
			sprintf(temp_full_path , "%s/%s", dir, entry->d_name );
			//printdir(entry->d_name, depth+4);
			printdir( temp_full_path, depth+4);
		}
		else
		{
			//printf("%*s%s\n",depth,"",entry->d_name);
			char check_path[255] = {0};memset(check_path, 0, sizeof(check_path));
			sprintf(check_path ,"%s/%s", dir,entry->d_name);
			if( strcmp("ReadOrder.txt", entry->d_name) == 0 )
			{
				checkReadorder(check_path);
			}

		}
	}
	chdir("..");
	closedir(dp);
}

int main(int argc, char **argv)
{
	if(argc<2)
	{
		printf("Usage: ./check foderpath\n");
		return -1;
	}
	
//	printf("Diectory of %s:\n", argv[1]);
	printdir(argv[1], 0);
	printf("done\n");
	exit(0);

}

