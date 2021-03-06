#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t count_nozero = PTHREAD_COND_INITIALIZER;
unsigned int count = 0;

void *increment_count(void *arg)
{
    int msec = *(int *)arg;
    struct timespec req;
    
    req.tv_sec = msec / 1000;
    req.tv_nsec = (msec % 1000) * 1000000;
    nanosleep(&req, NULL);
    
    pthread_mutex_lock(&count_lock);
    count += 1;
    printf("debug sl bcount %d\n", count);
    pthread_cond_signal(&count_nozero);
    pthread_mutex_unlock(&count_lock);
    //pthread_cond_signal(&count_nozero);
    
    return NULL;
}

/* 
gcc -g -O2 -Wall thread.c -o thread -lpthread 

[lgr@localhost lab]$ ./thread 20
debug sl bcount 1
res:0
debug acount 1

[lgr@localhost lab]$ ./thread 2000
res:110
debug acount 0

*/
int main(int argc, char *argv[])
{
    struct timespec m_time;
    pthread_t reader2;
    int res = 0;
    int msec; /* �߳����ߵĺ����� */

    if (argc < 2) exit(1);
    msec = atoi(argv[1]);
    
    pthread_create(&reader2, NULL, increment_count, &msec);

    m_time.tv_sec = time(NULL) + 1;
    m_time.tv_nsec = 0;

//    printf("m_time.tv_sec  =%s\n",m_time.tv_sec);
    
    pthread_mutex_lock(&count_lock);
    while(count == 0 && res != ETIMEDOUT)
        res = pthread_cond_timedwait(&count_nozero, &count_lock, (const struct timespec *)&m_time);
    pthread_mutex_unlock(&count_lock);
    
    printf("res:%d\n", res);
    if(res==ETIMEDOUT)
    	printf("timeout\n");
    printf("debug acount %d\n", count);
    return 0;
}
