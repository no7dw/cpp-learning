#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

	pid_t pid;
	int ret;
	
	//create a child process
	if((pid=fork())<0)
	{
		printf("Fork error");
		exit(1);
	}

	if(pid==0)
	{
		// the child process send SIGSTOP signal ,making the child process pause
		printf("Child(pid: %d ) is waiting for any sinal\n ",getpid());
		raise(SIGSTOP);
		exit(0);
	}
	else
	{
		if((waitpid(pid,NULL,WNOHANG))==0)
		{
			printf("Parent kill %d\n",getpid());
		}
	}
	waitpid(pid,NULL,0);
	exit(0);
	
}
