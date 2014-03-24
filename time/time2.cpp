
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define ERROR_LOG "/tmp/hdd/volumes/HDD1/error_log"

char* UTIL_GetLocalTimeString(bool bwithlink)
{
	
	time_t tNow = time( NULL );
	char pTime[256];
	memset(pTime, 0 , sizeof(char)* 256);
	strftime(pTime, sizeof(char)*256, "%Y-%m-%d %H:%M:%S",localtime(&tNow));		 
	
	return pTime;
}


int UTIL_WriteErrUploadData(const char * logfile, const char *strErHash, int iErrorType)
{
	if(strcmp( strErHash , "" ) == 0)
		return -1;
	
	int iRet = -1;
	
	while(1)
	{
		
		printf("UTIL_WriteErrUploadData ()  Hash: %s \n", strErHash );
		FILE* pfdErrorLog;
		
		time_t tNow = time( NULL );
		//char *szTime = asctime( localtime( &tNow ) );
		//szTime[strlen( szTime ) - 1] = '\0';
		
		char pTime[256];
		memset(pTime, 0 , sizeof(char)* 256);
		strftime(pTime, sizeof(char)*256, "%Y-%m-%d %H:%M:%S",localtime(&tNow));
	
		pfdErrorLog = fopen( logfile ,"a" );
		char err_log[500];memset(err_log, 0, sizeof(err_log));
		sprintf(err_log, "%s # Hash: %s # EType: %d\n", pTime , strErHash , iErrorType);
		fwrite( err_log, sizeof(char), strlen(err_log),pfdErrorLog);
		fclose(pfdErrorLog);
		//解锁/****************** V *********************/
		
		break;
	}

	return iRet;
}
int main(void)
{
	UTIL_WriteErrUploadData(ERROR_LOG, "78ff727f5a3566f3e1dbe7657349f01ddf410b6c", 1);
	UTIL_WriteErrUploadData(ERROR_LOG, "beadf2e21ad586df442cedb5b29b82a016516307", 2);
	UTIL_WriteErrUploadData(ERROR_LOG, "ca732f1e4b7d772eb1cc87c237142eb6d547c117", 2);
	
	sleep(1);
	char epath[200] = {0}; memset(epath, 0, sizeof(epath));
	sprintf(epath, "cat %s", ERROR_LOG);
	system(epath);
	sleep(2);
	
	FILE	*fp = NULL;
	char	buf[500];memset(buf, 0, sizeof(buf));
	
	if ((fp = fopen(ERROR_LOG, "r")) == NULL) 
	{
		printf("open ServerBTERROR_LOG %s fail Not Exist , May be No BUG!\n", ERROR_LOG);
		return 1;
	}

	while (fgets(buf, sizeof(buf), fp)) 
	{		
		//strftime : 2012-04-26 10:58:17 strlen(pTime)=19
		char ErrorTime[20] = {0};memset(ErrorTime,0 ,sizeof(ErrorTime));
		strncpy(ErrorTime, buf, 19);
		printf("time %s \t descri:%s", ErrorTime, buf+19+1);
		//erroroutput(LGSYSTEM_ERROR, buf+19+1, ErrorTime);//19= time length, 1 space //read each line then input to updatelog 
	}
	fclose(fp);
}
