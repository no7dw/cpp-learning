#include <semaphore.h>
#include <stdio.h>

sem_t sem1;
int main(void)
{
	
	sem_init(&sem1, 0 ,0);
	int value1 = 0;
	sem_getvalue(&sem1, &value1);
	printf("init value1 := %d\n", value1);
	
	sem_post(&sem1);
	sem_getvalue(&sem1, &value1);
	printf("after post value1 := %d\n", value1);
	
	sem_post(&sem1);
	sem_getvalue(&sem1, &value1);
	printf("after post value1 := %d\n", value1);
	
	sem_post(&sem1);
	sem_getvalue(&sem1, &value1);
	printf("after post value1 := %d\n", value1);
	
	sem_wait(&sem1);
	sem_getvalue(&sem1, &value1);
	printf("after wait value1 := %d\n", value1);

	sem_wait(&sem1);
	sem_getvalue(&sem1, &value1);
	printf("after wait value1 := %d\n", value1);

	sem_wait(&sem1);
	sem_getvalue(&sem1, &value1);
	printf("after wait value1 := %d\n", value1);

	sem_wait(&sem1);
	sem_getvalue(&sem1, &value1);
	printf("after wait value1 := %d\n", value1);

	sem_wait(&sem1);
	sem_getvalue(&sem1, &value1);
	printf("after wait value1 := %d\n", value1);

	sem_destroy(&sem1);
}
