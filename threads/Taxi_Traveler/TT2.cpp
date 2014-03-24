#include <iostream>
#include <pthread.h>
using namespace std;
 // 提示出租车到达的条件变量

 pthread_cond_t taxiCond;
 // 同步锁

 pthread_mutex_t traveler_Mutex;
 pthread_mutex_t taxi_Mutex;
 int sum = 0;//记数变量,来确定有人要坐车

 // 旅客到达等待出租车
 void * traveler_arrive(void * name)
 {
    cout<< "Traveler: " <<(char *)name<< " needs a taxi now! " <<endl;
    pthread_mutex_lock(&traveler_Mutex);
    ++sum;
    pthread_cond_wait(&taxiCond, &traveler_Mutex);
    pthread_mutex_unlock (&traveler_Mutex);
    cout<< "Traveler: " << (char *)name << " now got a taxi! " <<endl;
    pthread_exit( (void *)0 );
 }

 // 出租车到达
 void * taxi_arrive(void *name)
 {
    cout<< "Taxi " <<(char *)name<< " arrives. " <<endl;
    pthread_mutex_lock(&taxi_Mutex);//锁上发信号部分，防止后来的司机比先来的接走客人

    while(1)//不停的循环直到有客户来
    {
		if(sum > 0)//来了客户，发出一个接走客户的信号，然后完成此线程

		{
		cout << (char*)name << " take you go!" << endl;
			pthread_cond_signal(&taxiCond);
		--sum;
		pthread_mutex_unlock(&taxi_Mutex);
		break;
		}
		}
		pthread_exit( (void *)0 );
	}

	int main()
	{ 
		// 初始化
    pthread_mutexattr_t attr;//用于定义互斥锁属性

    taxiCond= PTHREAD_COND_INITIALIZER;
    traveler_Mutex= PTHREAD_MUTEX_INITIALIZER;
    taxi_Mutex = PTHREAD_MUTEX_INITIALIZER;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(&traveler_Mutex,&attr);//防止递归加锁后出现死锁

    pthread_mutex_init(&taxi_Mutex,&attr);

    pthread_t thread[10];

    pthread_attr_t threadAttr;//初始化并加上线程属性

    pthread_attr_init(&threadAttr);//这样设置以后，线程结束就会自动回收其占有的资源

    pthread_attr_setdetachstate(&threadAttr,PTHREAD_CREATE_DETACHED);

	pthread_create(&thread[0], &threadAttr, taxi_arrive, (void *)("Taxi1"));
    sleep(1);
    pthread_create(&thread[2], &threadAttr, traveler_arrive, (void *)("Traveler1"));
    sleep(1);
    pthread_create(&thread[4], &threadAttr, traveler_arrive, (void *)("Traveler2"));
    sleep(1);
    
    pthread_create(&thread[6], &threadAttr, traveler_arrive, (void *)("Traveler3"));
    sleep(1);
    pthread_create(&thread[1],&threadAttr,taxi_arrive,(void*)("Taxi2"));
    sleep(1);
    pthread_create(&thread[3],&threadAttr,taxi_arrive,(void*)("Taxi3"));
    sleep(1);
    pthread_create(&thread[8],&threadAttr,traveler_arrive,(void*)("Traveler4"));
    sleep(1);
    pthread_create(&thread[5], &threadAttr, taxi_arrive, (void *)("Taxi4"));
    sleep(1);
    return 0;
}
