#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
pid_t pid;
int counter=2;
void handler1(int sig)
{
	counter = counter-1;
	printf("handler1: %d\n", counter);
	fflush(stdout);
	exit(0);
}
int main(void)
{
	signal(SIGUSR1, handler1);
	printf("ori: %d\n", counter);
	fflush(stdout);
	if((pid=fork())==0)//child
	{
		while(1){};
	}
	kill(pid, SIGUSR1);
	waitpid(-1, NULL,0);
	counter=counter+1;
	printf("end parent: %d\n", counter);
	exit(0);

}
