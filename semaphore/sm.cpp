#include "sem_base.h"

int pause_time;
char* op_char = NULL;

int do_my_job(void)
{
	printf("%s is doing job\n", op_char);
	fflush(stdout);
	pause_time = rand()%3;
	sleep(pause_time);
	printf("%s is done\n", op_char);
	fflush(stdout);


}
int main(int argc, char *argv[])
{
	int i;
	srand((unsigned int)getpid());
	int sem_id;
	/*
	sem_id = semget((key_t)4321, 1, 0666);
	printf("sem_id_%s = %d\n",argv[1], sem_id);
	if(sem_id < 0)*/
	CSem *pCS = new CSem(4321);	

	
		if(!pCS)
		{
			fprintf(stderr, "Failed to initlize semaphore\n");
			exit(EXIT_FAILURE);
		}	

		op_char = argv[1];
		//sleep(2);		
	

	for(i = 0; i< 10; i++)	
	{
	/****************** P *********************/
		if(!(pCS->semaphore_p()))
			exit(EXIT_FAILURE);

		do_my_job(); //do something

	/****************** V *********************/
		if(!(pCS->semaphore_v()))
			exit(EXIT_FAILURE);


		pause_time = rand()%2;
		//sleep(pause_time);

	}//for

	printf("\n%d - finished \n", getpid());

	if(argc > 1)
	{
		//sleep(10);
// 		del_semvalue(sem_id);
	}
	delete pCS;
	exit(EXIT_SUCCESS);
}
