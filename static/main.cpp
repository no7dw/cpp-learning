#include "status.h"
#include <pthread.h>
#include <stdio.h>
pthread_t pid;
void *thread_mod(void*)
{
	
	for(int i = 0; i < 10; i++)
		status::mod();
	
	status::output();
	pthread_exit(NULL);
}

int main(void)
{

	status::output();
	status::mod();
	printf(" mod by main\n");
	status::output();
//	for(int i = 0; i < 10; i++)
//		status::mod();
	printf(" mod by thread\n");
	pthread_create( &pid, NULL, thread_mod, NULL);
	pthread_join( pid, NULL);
	printf("in main output \n");
	status::output();
}
