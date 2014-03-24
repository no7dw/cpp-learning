//#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <vector>
#include "time.h"
#include "Util.h"
using namespace std;


void UTIL_LogPrint( const char *format, ... )
{
	/*
	time_t tNow = time( NULL );
	char *szTime = asctime( localtime( &tNow ) );
	szTime[strlen( szTime ) - 1] = '\0';

	gmtxOutput.Claim( );

	printf( "[%s] ", szTime );

	va_list args;
	va_start( args, format );
	vprintf( format, args );
	va_end( args );

	if( !gstrErrorLogDir.empty( ) )
	{
		char pTime[256];
		memset( pTime, 0, sizeof( char ) * 256 );
		strftime( pTime, sizeof( char ) * 256, "%Y-%m-%d", localtime( &tNow ) );

		string strFile = gstrErrorLogDir + pTime + "e.log";

		if( gstrErrorLogFile != strFile )
		{
			// start a new log

			gstrErrorLogFile = strFile;

			if( gpErrorLog )
			{
				fclose( gpErrorLog );

				gpErrorLog = NULL;
			}

			gpErrorLog = fopen( strFile.c_str( ), "ab" );
		}

		if( gpErrorLog )
		{
			fprintf( gpErrorLog, "[%s] ", szTime );

			va_list args;
			va_start( args, format );
			vfprintf( gpErrorLog, format, args );
			va_end( args );

			giErrorLogCount++;

			if( giErrorLogCount % giFlushInterval == 0 )
				fflush( gpErrorLog );
		}
	}

	gmtxOutput.Release( );
	*/
	//::OutputDebugString(format);
}
void UTIL_DeleteFile( const char *szFile )
{
	if( unlink( szFile ) == 0 )
		UTIL_LogPrint( "deleted \"%s\"\n", szFile );
	else
	{
#ifdef WIN32
		UTIL_LogPrint( "error deleting \"%s\"\n", szFile );
#else
		UTIL_LogPrint( "error deleting \"%s\" - %s\n", szFile, strerror( errno ) );
#endif
	}
}


void UTIL_MakeFile( const char *szFile, string strContents )
{
	FILE *pFile = NULL;

	if( ( pFile = fopen( szFile, "wb" ) ) == NULL )
	{
		UTIL_LogPrint( "warning - unable to open %s for writing\n", szFile );

		return;
	}

	fwrite( (void *)strContents.c_str( ), sizeof( char ), strContents.size( ), pFile );
	fclose( pFile );
}
/*
void UTIL_MakeFile( const char *szFile, string strContents, bool Cover )
{
	UTIL_DeleteFile( szFile);

	UTIL_MakeFile( szFile, strContents );
}
*/
bool UTIL_CheckFile( const char *szFile )
{
	// check if file exists

	FILE *pFile = NULL;

	if( ( pFile = fopen( szFile, "r" ) ) == NULL )
		return false;

	fclose( pFile );

	return true;
}


string UTIL_ReadFile( const char *szFile )
{
	FILE *pFile = NULL;

	if( ( pFile = fopen( szFile, "rb" ) ) == NULL )
	{
		UTIL_LogPrint( "warning - unable to open %s for reading\n", szFile );

		return string( );
	}
	UTIL_LogPrint( "open %s for reading\n", szFile );

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


void UTIL_MoveFile( const char *szFile, const char *szDest , bool Cover )
{
	 
	if( UTIL_CheckFile( szDest ) && Cover == false )
		UTIL_LogPrint( "error archiving \"%s\" - destination file already exists\n", szDest );
	else//覆盖	
	//	UTIL_MakeFile( szDest, UTIL_ReadFile( szFile ), Cover );
		UTIL_MakeFile( szDest, UTIL_ReadFile( szFile ) );
	

	// thanks MrMister

	UTIL_DeleteFile( szFile );
}

void UTIL_CopyFile( const char *szFile, const char *szDest  , bool Cover )
{
	if( UTIL_CheckFile( szDest ) && Cover == false )
		UTIL_LogPrint( "error archiving \"%s\" - destination file already exists\n", szDest );
	else
//		UTIL_MakeFile( szDest, UTIL_ReadFile( szFile ) , Cover );
		UTIL_MakeFile( szDest, UTIL_ReadFile( szFile )  );

}


string UTIL_GetLocalTimeString()
{
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime ); 
	char year[5];
	char mon[3];
	char day[3];
	char hour[3];
	
	char min[3];
	char sec[3];

	strftime(year,5,"%Y",timeinfo);
	strftime(mon,3,"%m",timeinfo);
	strftime(day,3,"%d",timeinfo);
	strftime(hour,3,"%H",timeinfo);
	strftime(min,3,"%M",timeinfo);
	strftime(sec,3,"%S",timeinfo);
	 
	string timestr;
	timestr.append(year);
	timestr.append(mon);
	timestr.append(day);
	timestr.append(hour);
	timestr.append(min);
	timestr.append(sec);

	return timestr;
}

void CreateDir(const char *DirPath)
{
	//CreateDirectory(DirPath,NULL);
}

/*
//splitString函数的参数说明：  
//返回值是分割后字符串数组大小  
//strSrc 原始字符串  
//strDelims 自定义的分割字符串的分割数组  
//strDest 分割后的字符串数组，引用传递  
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
      
*/


