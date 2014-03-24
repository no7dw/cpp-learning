#include "p.h"


#define HEADSIZE 1000
#define BT_SETTING_PARA_SIZE 5


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

string UTIL_ReadFile( const char *szFile ,  long &lFileSize )
 {
	FILE *pFile = NULL;

	if( ( pFile = fopen( szFile, "rb" ) ) == NULL )
	{
	  return string();
	}
	fseek( pFile, 0, SEEK_END );
	long ulFileSize = ftell( pFile );
	lFileSize = ulFileSize;
	  
	return   UTIL_ReadFile( szFile );
 }

TorrentResult AnalyseReceiveBuffer(const string &RecvBuffer, HtmlPage htmlpage)
{
	
    TorrentResult tr_result  = TORRENT_RESULT_UNKNOW;
    
    if( RecvBuffer.find(STR_OK_200)!=string::npos )//found 
    {
	switch(htmlpage)
	{
	  case PAGE_ADD_TORRENT:
	  {
	      
	      if(RecvBuffer.find("torrent add failed") !=string::npos)
	      {
		  cout <<"### OH NO~ We catch a error called : torrent add failed" << endl;
		  tr_result = TORRENT_RESULT_TORRENT_ADD_FAIL;
	      }
	      else if(RecvBuffer.find("Error, torrent already exists") !=string::npos)
	      {  
		  cout <<"### OH NO~ We catch a error called : Error, torrent already exists" << endl;
		  tr_result = TORRENT_RESULT_TORRENT_EXISTS_Already;
	      }	      
	      else if(RecvBuffer.find("HTTP-EQUIV=") !=string::npos)//HTTP-EQUIV=""REFRESH""
	      {
		  cout <<"### WOW~ We did it" << endl;
		  tr_result = TORRENT_RESULT_SUCCESS;
	      }
	      else
	      {
		  cout <<"### Oh~ We don't know the result !" << endl;
		  tr_result = TORRENT_RESULT_UNKNOW;
	      }
	  }
	    break;
	  case PAGE_SETTING_GET:
		tr_result = TORRENT_RESULT_SUCCESS;  
		break;
	   case PAGE_SETTING_SET:
		tr_result = TORRENT_RESULT_SUCCESS;  
		break;
	   case PAGE_JOB_STATUS:
		tr_result = TORRENT_RESULT_SUCCESS;  
		break;
	  default :
		tr_result = TORRENT_RESULT_UNKNOW;
		break;
	}
    }
    else//error message
    {
      
    }
    return tr_result;  
      
}
int PostTorrent(const char *IPAddressOfTargetHost , const char *TorrentFilePath)
{
	
	cout << " TorrentFilePath = " << TorrentFilePath << endl;
        int sockfd;
        int len;
        struct sockaddr_in address;
        int result;

/////////////////////ReadFile/////////////////////////////////////////////
	long ulFileSize = 0;
	
	string strRet = UTIL_ReadFile( TorrentFilePath ,ulFileSize );
	printf("ulFileSize = %ld" ,ulFileSize);
	
	//cout << " strRet = " << strRet.substr( 0, 100) << endl;//just printf 100 char
	char pData[ulFileSize];
	
	memset( pData, 0 , ulFileSize );
	memcpy( pData, strRet.c_str() , ulFileSize ); 
////////////////////////////////////////////////////////////////////////
	
        char pHeadOne[HEADSIZE] = "POST /cgi-bin/UniCGI.cgi?id=7 HTTP/1.1\r\nHost: 192.168.2.11:\r\nContent-Length:";//76
        char pHeadTwo[HEADSIZE] = "\r\nContent-Type: multipart/form-data; boundary=---------------------------7db4cf4022c\r\nConnection: Keep-Alive\r\n\r\n";//112
        char pHeadThree[HEADSIZE] = "-----------------------------7db4cf4022c\r\nContent-Disposition: form-data; name=\"addf\"; filename=\"/tmp/3.torrent\"\r\nContent-Type: application/x-bittorrent\r\n\r\n";//156

        char pHeadFour[HEADSIZE] = "\r\n-----------------------------7db4cf4022c--\r\n";//46
       
        char fileLengthBuffer[10];
	
        //itoa(lenOfContent + strlen(pHeadThree) + strlen(pHeadFour),fileLengthBuffer,10); //change int to ascii char *
	memset(fileLengthBuffer,0,sizeof(char)*5);
	long fileLength = ulFileSize + strlen(pHeadThree) + strlen(pHeadFour);
	sprintf(fileLengthBuffer, "%d",fileLength);

	
        long packLength = strlen(pHeadOne) + strlen(fileLengthBuffer) + strlen(pHeadTwo) + strlen(pHeadThree) + ulFileSize + strlen(pHeadFour);
        char pSndbuf[packLength+1]; 
	//char pSndbuf[packLength]; 
        memset(pSndbuf, 0 , sizeof(char)*packLength );
	char *pS2=pSndbuf;

	memcpy(pSndbuf,pHeadOne,strlen(pHeadOne));
        memcpy(pSndbuf+strlen(pHeadOne),fileLengthBuffer,strlen(fileLengthBuffer));
        memcpy(pSndbuf+strlen(pHeadOne)+strlen(fileLengthBuffer),pHeadTwo,strlen(pHeadTwo));
        memcpy(pSndbuf+strlen(pHeadOne)+strlen(fileLengthBuffer)+strlen(pHeadTwo),pHeadThree,strlen(pHeadThree));
        
	memcpy(pSndbuf+strlen(pHeadOne)+strlen(fileLengthBuffer)+strlen(pHeadTwo)+strlen(pHeadThree),pData,ulFileSize); 
        memcpy(pSndbuf+strlen(pHeadOne)+strlen(fileLengthBuffer)+strlen(pHeadTwo)+strlen(pHeadThree)+ulFileSize,pHeadFour,strlen(pHeadFour));

	pSndbuf[packLength]='\0';	
	
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd == -1)
        {
                perror("socket");
                return -1;
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr( IPAddressOfTargetHost );
        address.sin_port = htons(PORT);

        len = sizeof(address);
        result = connect(sockfd,  (struct sockaddr *)&address, len);
        if(result == -1)
        {
                perror("connect");

                return -1;
        }

        printf("connect success!\n");

        // write(sockfd,strings,strlen(strings));
        
	int totalsize;
	totalsize =strlen(pHeadOne)+strlen(fileLengthBuffer)+strlen(pHeadTwo)+strlen(pHeadThree) +ulFileSize +strlen(pHeadFour)+1;
        int sendbytes;
        if( ( sendbytes = send(sockfd, pSndbuf, totalsize, 0)) == -1)
        {
		close(sockfd);
                perror("send");
                return -1;
        }

        printf("\nsendbytes = %d\n", sendbytes);
	printf("\n=======THE FOLLOWING IS RECEIVE FROM SOCKET========\n");

	char RecvBuffer[1000];
	int iRecv = 1;
	TorrentResult TR = TORRENT_RESULT_UNKNOW;
	while( iRecv > 0 )
	{
	    iRecv = recv( sockfd, RecvBuffer, sizeof(RecvBuffer), 0);
	    if( iRecv > 0 )
	        {RecvBuffer[iRecv]=0;}
	    else
	        {RecvBuffer[0]=0;}
	    
	    printf("\nReceived   bytes:%d\n",iRecv);
	    //printf("Result:%s\n",RecvBuffer);
	    
	    //just printf 100 char
	    string strsub;
	    strsub.assign(RecvBuffer, 100);
	    printf("Result of sub 100 %s\n", strsub.c_str());
	    	    
	    //analyse the return to find out whether succeed or not
	    string strRecvBuf ;
	    strRecvBuf.assign(RecvBuffer, strlen(RecvBuffer));
	    TR = AnalyseReceiveBuffer(RecvBuffer ,PAGE_ADD_TORRENT);
	    
	    close(sockfd);
	    printf("\n==================================================\n");		        
            printf("sizeof(pSndbuf)%d\n",sizeof(pSndbuf));
	    return 0;
	}
	
        //memset(strings,0,strlen(strings));
        return 0;

}

int main(int argc , char **argv)
{
	if(argc<2)
	{
		printf("usage: PostTorrent IP torrentFilePath \n");
		return -1;
	}
		return 	PostTorrent( argv[1],argv[2]);

}

