#include "w.h"

pthread_mutex_t TaskControl::count_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t TaskControl::count_cond = PTHREAD_COND_INITIALIZER;
unsigned int TaskControl::count = 0;

//20 sec
#define WGET_TIME_OUT_MSEC 20*1000

void *TaskControl::increment_count(void *arg)
{
    char carg[300] = {0};
    strcpy(carg, (char*)arg);
    printf("\n cmd = %s \n",carg);
    system(carg);
    //system("wget ftp://192.168.100.3:22/lgftp/1.bmp -O 1.bmp --user LangeFtpUser --password LangeFtpPwd*_!");
    count += 1;
    pthread_mutex_lock(&count_lock);
    pthread_cond_signal(&count_cond);
    pthread_mutex_unlock(&count_lock);
    
    pthread_exit(NULL);
}

int TaskControl::Task_Add(const char *TorrentHash)//hash
{

	if(strcmp(TorrentHash,"")==0)//检查输入
		return -1;

	//构造下载命令
	char strTorrentPath[200] = {0};
	strcat(strTorrentPath ,  "http://");
	strcat(strTorrentPath , BNBT_SERVER_IP);
	strcat(strTorrentPath ,":");
	strcat(strTorrentPath ,BNBT_SERVER_PORT);
	
	
	strcat(strTorrentPath ,"/torrent.html?info_hash=");
	strcat(strTorrentPath ,TorrentHash);//hash
		
	char strWgetCmd[300] = {0};
	strcat(strWgetCmd , "wget ");
	//need add some parameters to download @ -O /tmp/xx.torrent for only it's writable
	//-o,  --output-file=FILE    log messages to FILE.
	//-O,  --output-document=FILE    write documents to FILE
	strcat(strWgetCmd ,strTorrentPath);    
	strcat(strWgetCmd ," -O ");//-o will output to 
		
	strcat(strWgetCmd , TORRENT_SAVE_PATH);    
		
	//system(strWgetCmd.c_str());
	pthread_cond_init(&count_cond,NULL);
	struct timespec m_time;
	count = 0;
	pthread_t reader2;
	int res = 0;
	int msec; /*time out millionsec  */    
	msec = WGET_TIME_OUT_MSEC;
	
	pthread_create(&reader2, NULL, increment_count, (void*)strWgetCmd);
	
	/* get the current time */ 
	struct timeval now; 
	gettimeofday(&now, NULL); 
		
	/* add the offset to get timeout value */ 
	m_time.tv_nsec = now.tv_usec * 1000 + (msec % 1000) * 1000000; 
	m_time.tv_sec = now.tv_sec + msec / 1000;


	pthread_mutex_lock(&count_lock);
	while(count == 0 && res != ETIMEDOUT)
		res = pthread_cond_timedwait(&count_cond, &count_lock, (const struct timespec *)&m_time);
	
	pthread_mutex_unlock(&count_lock);
	printf("res:%d\n", res);
	
	int iRet = 0;
	if(res == ETIMEDOUT)
	{
		printf("\n\n********* timeout **********\n\n");
	//	if (pthread_kill(reader2,0)!=0)
		{
			printf("\n********* pthread_cancel **********\n");
			pthread_cancel(reader2);
		}
		
		iRet = -1;
	}
	pthread_join(reader2, NULL);
	pthread_cond_destroy(&count_cond);
	
	if(iRet == -1)
	{
		return iRet;
	}
	else
	{
		
		printf(" finish in time ,res = %d, count =%d\n", res , count);
				

		return 0;
	}
}

