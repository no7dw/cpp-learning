#include <stdio.h>
#include <pthread.h>
#include <iostream>
using namespace std;
// the condition notify the taxi has arrive
pthread_cond_t taxiCond;
//the mutex lock 
pthread_mutex_t taxiMutex;

void *traveler_arrive(void *name)
{
	cout << " Traveler: "<< (char *)name << " needs a taxi now!" << endl;
	pthread_mutex_lock(&taxiMutex);
	pthread_cond_wait(&taxiCond,&taxiMutex);
	pthread_mutex_unlock(&taxiMutex);
	cout << " Thraveler: " << (char *)name << " now got a taxi!"<< endl;
	pthread_exit((void *)0);

}

void *taxi_arrive(void *name)
{
	cout << " Taxi "<< (char*)name <<" arrives."<< endl;
	pthread_cond_signal(&taxiCond);
	pthread_exit((void *)0);

}

int main()
{
	taxiCond = PTHREAD_COND_INITIALIZER;
	taxiMutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_t thread;
	pthread_attr_t threadAttr;
	pthread_attr_init(&threadAttr);
	
	pthread_create(&thread,&threadAttr,taxi_arrive,(void *)(" Jack "));
	sleep(3);
	pthread_create(&thread,&threadAttr,traveler_arrive,(void *)(" Susan "));
	sleep(3);
	pthread_create(&thread,&threadAttr,taxi_arrive,(void *)(" Mike "));
	sleep(3);

	return 0;

}



