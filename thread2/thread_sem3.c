#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUMBER 2 //线程数目

int iPlay_Thread=0;//播放次数
int iRecord_Thread=0;//录音的次数

sem_t sem;//播放与录音同步的信号量

void *Playctrl_pthread(void *args)
{
	printf("\n\n Play Thread  begin \n");
	int delay_time = 5;	
	

	while(1)	
	{
		
			//当播放真正开始 

			sem_post(&sem);
			printf(" Play Thread is starting \n");

				
			printf("%d Play Thread doing working for %d secs  \n",iPlay_Thread++ , delay_time);
			sleep(delay_time);//代表播放过程
			printf("Play Thread  finished\n");
	
		
	}

	printf("Play Thread  finished\n");
	pthread_exit(NULL);
}

void *Record_pthread(void *args)
{
	int delay_time = 5;
	printf("\n\n Record Thread  begin \n");

	while(1)	
	{
		
	
			sem_wait(&sem);//等待播放真正开始
			printf(" Record Thread is starting \n");

				
			printf("%d Record Thread doing working for %d secs  \n",iRecord_Thread++ , delay_time);
			sleep(delay_time);//代表录音过程
			printf("Record Thread  finished\n");
		
	}

	printf("Record Thread  finished\n");
	pthread_exit(NULL);
	
}


int main(void)
{
	pthread_t thread[THREAD_NUMBER];
	int no=0,res;
	void *thrd_ret;

	
	sem_init(&sem, 0 ,0 );//初始化

		
//	res=pthread_create(&thread[no],NULL,Playctrl_pthread,(void*)this);//类里面传this
	res=pthread_create(&thread[no],NULL,Playctrl_pthread,NULL);//no = 0 play thread ,no = 1 record thread
		
	if(res!=0)
	{
		printf("Create play thread %d fail\n",no);
		exit(res);
	}
	no++;//下一个thread id
//	res=pthread_create(&thread[no],NULL,Record_pthread,(void*)this);//这里考虑传录音的相关参数，如录音时间
	res=pthread_create(&thread[no],NULL,Record_pthread,NULL);//no 0 Record thread , 1 record thread
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

	
	sem_destroy(&sem);//销毁
	return 0;

}


