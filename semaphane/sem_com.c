#include "sem_com.c"
/*
 #include <stdlib.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
*/
int init_sem(int sem_id, int init_value)
{
	union semun sem_union;
	sem_union.val=init_value;
	if(semctl(sem_id,0,SETVAL,sem_union)==-1)
	{
		perror("Initialize semaphore\n");
		return -1;
	}
	return 0;
}

//del semaphore
int del_sem(int sem_id)
{
	union semun sem_union;
	if(semctl(sem_id,0,IPC_RMID,sem_union)==-1)
	{
		perror("Delete semaphore");
		return -1;
	}
	return 0;
}

//P
int sem_p(int sem_id)
{
	struct sembuf sem_b;
	sem_b.sem_num=0;
	sem_b.sem_op=-1;
	sem_b.sem_flg=SEM_UNDO;
	if(semop(sem_id,&sem_b,1)==-1)
	{
		perror("P operation\n");
		return -1;
	}
	return 0;
}

//V
int sem_p(int sem_id)
  {
          struct sembuf sem_b;
          sem_b.sem_num=0;
          sem_b.sem_op=1;
          sem_b.sem_flg=SEM_UNDO;
          if(semop(sem_id,&sem_b,1)==-1)
          {
                  perror("V operation\n");
                  return -1;
          }
          return 0;
  }


