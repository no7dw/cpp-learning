#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

string UTIL_ReadFile( const char *szFile )
{
	FILE *pFile = NULL;

	if( ( pFile = fopen( szFile, "rb" ) ) == NULL )
	{		
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

static void al_hr(int signo)
{
	printf("in al_hr handle timeout here\n");
	return ;
}


#define INTERNET
static int domyjob()
{
	/***** timer ******/	
#ifdef INTERNET
	const char* CHECK_URL = "www.baidu.com";
#else
	const char* CHECK_URL = "192.168.2.24";
#endif
	const char* PING_RESULT = "/tmp/ping_url_result";
	
	char check_net[256] ;memset(check_net, 0 , sizeof(check_net));
	sprintf( check_net , "%s %s -c 1 > %s " , "ping", CHECK_URL ,  PING_RESULT);
	
	printf(" check_net :%s \n",check_net);
	
	system(check_net);
	string strResult = UTIL_ReadFile(PING_RESULT);
	if(strResult.find("is alive") != string::npos)
	{
		printf("connected\n");
		return 0;//net work is connected
	}
	else if((strResult.find("No response") != string::npos ) 
		|| (strResult.find("Unknown host") != string::npos) 
		|| strResult.find("Destination Host Unreachable") != string::npos )
		//No response or  Unknown host
	{
		printf("disconnected\n");
		return -1;//disconnected;
	}	
}
int main(int argc , char *argv[])
{
	if(argc<3)
	{
		printf("%s nsec_timeout nsec_sleep_test\n",argv[0]);
		return -1;
	}

	int nsec = atoi(argv[1]);
	int nsecsleep = atoi(argv[2]);
	typedef void    Sigfunc(int);
	Sigfunc *sigfunc;
	sigfunc = signal(SIGALRM, al_hr);
	if(alarm(nsec)!=0)
	{
		printf("alarm was set already!\n");
		return -1;
	}
	printf("after signal 1111\n");
	//sleep(nsecsleep);
	pid_t pid;
	if(pid = fork() < 0)
	{
		printf("fork eror");
	}
	else if(pid == 0)
	{
		printf("child");
		domyjob();
		printf("parent ****\n");
		printf("after sleep ...\n");
		if(errno == EINTR)
		{
			printf("ETIMEDOUT\n");
			errno = ETIMEDOUT;
		}
		alarm(0);//turn off
		signal(SIGALRM, sigfunc);//restore
		printf("before exit ...\n");
	}
	else
	{
		printf("parent ****\n");
		/*printf("after sleep ...\n");
		if(errno == EINTR)
		{
			printf("ETIMEDOUT\n");
			errno = ETIMEDOUT;
		}
		alarm(0);//turn off
		signal(SIGALRM, sigfunc);//restore
		printf("before exit ...\n");*/
	}
	exit(0);
}
