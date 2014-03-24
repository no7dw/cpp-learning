#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <string.h>
using namespace std;
// the condition notify the taxi has arrive
pthread_cond_t taxiCond;
//the mutex lock 
pthread_mutex_t taxiMutex;

char taxi_queue[3][10];
void Mark_queue(const char *name)
{
	for( int i= 0; i< 3 ; i++)
	{
		if(strlen(taxi_queue[i] == 0))
			strcpy( taxi_queue[i], name);			
	}
}
void *taxi_arrive(void *name)
{
	cout << " Taxi: "<< (char *)name << " arrive " << endl;
	cout <<"Lock begin "<< (char*)name << endl;
	pthread_mutex_lock(&taxiMutex);
//	Mark_queue((char*)name);
	pthread_cond_wait(&taxiCond,&taxiMutex);
	pthread_mutex_unlock(&taxiMutex);
	cout <<"UnLock end "<< (char*)name << endl;
	cout << " Taxi: " << (char *)name << " now drive off his taxi!"<< endl;
	pthread_exit((void *)0);

}

void *officer_arrive(void *name)
{
	cout << " officer "<< (char*)name <<" arrives."<< endl;
//		cout <<"Lock begin "<< (char*)name << endl;
		pthread_mutex_lock(&taxiMutex);

			cout << " officer "<< (char*)name <<" pthread_cond_signal "<< endl;
			pthread_cond_signal(&taxiCond);
			pthread_mutex_unlock(&taxiMutex);
			cout <<"  UnLock  "<< (char*)name << endl;
//		cout <<"UnLock end "<< (char*)name << endl;
	pthread_exit((void*) 0);
}

int main()
{
	memset(taxi_queue, 0, sizeof(taxi_queue));
	taxiCond = PTHREAD_COND_INITIALIZER;
	taxiMutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_t thread1, thread2, thread3;
	pthread_attr_t threadAttr;
	pthread_attr_init(&threadAttr);
	
	pthread_create(&thread1,&threadAttr,taxi_arrive,(void *)("Jack"));
	sleep(3);
	pthread_create(&thread1,&threadAttr,taxi_arrive,(void *)("David"));
	sleep(3);
	pthread_create(&thread2,&threadAttr,officer_arrive,(void *)("Susan"));
	sleep(3);
	pthread_create(&thread3,&threadAttr,taxi_arrive,(void *)("Mike"));
	sleep(3);

	return 0;

}



