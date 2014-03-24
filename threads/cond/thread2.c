#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t count_cond = PTHREAD_COND_INITIALIZER;
unsigned int count = 0;

void *increment_count(void *arg)
{
    
    system("wget ftp://192.168.100.3:22/lgftp/1.rmvb -O 1.rmvb --user LangeFtpUser --password LangeFtpPwd*_!");
    //system("wget ftp://192.168.100.3:22/lgftp/1.bmp -O 1.bmp --user LangeFtpUser --password LangeFtpPwd*_!");
    count += 1;
    pthread_mutex_lock(&count_lock);
    pthread_cond_signal(&count_cond);
    pthread_mutex_unlock(&count_lock);
    
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    struct timespec m_time;
    pthread_t reader2;
    int res = 0;
    int msec; /*time out millionsec  */

    if (argc < 2) exit(1);
    msec = atoi(argv[1]);
    
    pthread_create(&reader2, NULL, increment_count, NULL);

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
   
   if(res==ETIMEDOUT)
   {
    	printf("\n\n********* timeout **********\n\n");
//	if (pthread_kill(reader2,0)!=0)
	{
		printf("\n********* pthread_cancel **********\n");
		pthread_cancel(reader2);
	}
   }
   else
   {
	    printf(" finish in time ,res = %d, count =%d\n", res , count);
   }

    pthread_join(reader2, NULL);
    return 0;
}
