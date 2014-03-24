#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUMBER 2 
#define REPEAT_NUMBER 1
#define DELAY_TIME_LEVELS 10.0

int iPlay_Thread=0;
int iRecord_Thread=0;

sem_t sem;

void *Playctrl_pthread(void *args)
{
	int thrd_num =(int)args;
	printf("\n\n Play Thread  %d  begin \n",thrd_num);
	int delay_time = 5;	
	

	while(1)	
	{
		
		if(thrd_num == 0)//play thread 	
		{
			//when play is ready 

			sem_post(&sem);
			printf(" Play Thread  %d  is starting \n",thrd_num);

				
			printf("%d Play Thread doing working for %d secs  \n",iPlay_Thread++ , delay_time);
			sleep(delay_time);//代表播放过程
			printf("Play Thread  finished\n");
		}
	
		
	}

	printf("Thread %d finished\n",thrd_num);
	pthread_exit(NULL);
}

void *Record_pthread(void *args)
{
	int thrd_num =(int)args;
	int delay_time = 5;
	printf("\n\n Record Thread  %d  begin \n",thrd_num);

	while(1)	
	{
		
		if(thrd_num == 1)//play thread 	
		{
	
			sem_wait(&sem);
			printf(" Record Thread %d  is starting \n",thrd_num);

				
			printf("%d Record Thread doing working for %d secs  \n",iRecord_Thread++ , delay_time);
			sleep(delay_time);//代表录音过程
			printf("Record Thread  finished\n");
		}
		
	}

	printf("Thread %d finished\n",thrd_num);
	pthread_exit(NULL);
	
}


int main(void)
{
	pthread_t thread[THREAD_NUMBER];
	int no=0,res;
	void *thrd_ret;

	
	sem_init(&sem, 0 ,0 );

		
	res=pthread_create(&thread[no++],NULL,Playctrl_pthread,(void*)0);//no 0 play thread , 1 record thread
	if(res!=0)
	{
		printf("Create play thread %d fail\n",no);
		exit(res);
	}
	res=pthread_create(&thread[no],NULL,Record_pthread,(void*)1);//no 0 Record thread , 1 record thread
	if(res!=0)
	{
		printf("Create Record thread %d fail\n",no);
		exit(res);
	}
	
	
	printf("Create treads success!\n Waiting for thread to finish...\n");

	//sem_post(&sem);
	for(no=THREAD_NUMBER-1;no>=0;no--)
	{
		res=pthread_join(thread[no],&thrd_ret);
		if(!res)
		{
			printf("Thread %d joined\n",no);
		}
		else
		{
			printf("Thread %d joined fail\n",no);

		}
		
		sem_post(&sem);		

	}

	
	sem_destroy(&sem);
	return 0;

}


