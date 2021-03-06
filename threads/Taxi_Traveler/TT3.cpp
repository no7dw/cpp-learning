#include <stdio.h>
#include <pthread.h>
#include <iostream>
using namespace std;
// the condition notify the taxi has arrive
pthread_cond_t taxiCond;
//the mutex lock 
pthread_mutex_t taxiMutex;
pthread_mutex_t traMutex;
int travelerCount = 0;

void *traveler_arrive(void *name)
{
	cout << " Traveler: "<< (char *)name << " needs a taxi now!" << endl;
	cout <<"Lock begin "<< (char*)name << endl;
	pthread_mutex_lock(&traMutex);
	travelerCount++;
	pthread_cond_wait(&taxiCond,&traMutex);
	pthread_mutex_unlock(&traMutex);
	cout <<"UnLock end "<< (char*)name << endl;
	cout << " Traveler: " << (char *)name << " now got a taxi!"<< endl;
	pthread_exit((void *)0);

}

void *taxi_arrive(void *name)
{
	cout << " Taxi "<< (char*)name <<" arrives."<< endl;
	pthread_mutex_lock(&taxiMutex);
	while(true)
	{
		if(travelerCount>0)
		{
			cout << " Taxi "<< (char*)name <<" pthread_cond_signal"<< endl;
			pthread_cond_signal(&taxiCond);
			--travelerCount;
			pthread_mutex_unlock(&taxiMutex);
			cout <<"UnLock end "<< (char*)name << endl;
			break;
		}
	}
	pthread_exit((void*) 0);
}

int main()
{
	taxiCond = PTHREAD_COND_INITIALIZER;
	taxiMutex = PTHREAD_MUTEX_INITIALIZER;
	traMutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_t thread1, thread2, thread3, thread4, thread5;
	pthread_attr_t threadAttr;
	pthread_attr_init(&threadAttr);

	pthread_mutexattr_t attr;//用于定义互斥锁属性
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
	pthread_mutex_init(&taxiMutex, &attr);
	pthread_mutex_init(&traMutex, &attr);

	pthread_create(&thread1,&threadAttr,taxi_arrive,(void *)("DJack"));
	sleep(3);
	pthread_create(&thread2,&threadAttr,traveler_arrive,(void *)("TSusan"));
	sleep(3);
	pthread_create(&thread3,&threadAttr,taxi_arrive,(void *)("DMike"));
	sleep(3);
	pthread_create(&thread4,&threadAttr,traveler_arrive,(void *)("TSam"));
	sleep(3);
	pthread_create(&thread5,&threadAttr,taxi_arrive,(void *)("DWindy"));
	sleep(3);
	return 0;

}



