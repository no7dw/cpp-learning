#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void unix_error(const char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}
//this will generate a zombie process 
void handler2(int sig)
{
	pid_t pid;
	if((pid=waitpid(-1, NULL, 0))>0)
		printf("Handler reped child %d\n", (int)pid);
	else
		unix_error("waitpid error");
	sleep(2);
	return;
}
//this will process all signal when process the same signal
void handler2(int sig)
{
	pid_t pid;
	while((pid=waitpid(-1, NULL, 0))>0)
		printf("Handler reped child %d\n", (int)pid);
	if(errno!=ECHILD)
		unix_error("waitpid error");
	sleep(2);
	return;
}
#define MAXBUF 256
int main(void)
{
	int i, n;
	char buf[MAXBUF];
	if(signal(SIGCHLD, handler2)==SIG_ERR)
		unix_error("signal error");
	
	// parent creates children
	for(i = 0; i<3; i++)
	{
		if(fork()==0)
		{
			printf("Hello from child %d\n", (int)getpid());
			sleep(1);
			exit(0);
		}
	}
	while((n=read(STDIN_FILENO, buf, sizeof(buf)))<0)
		if(errno!=EINTR)
			unix_error("read error");
	
	printf("parent processing input\n");
	//when running in this loop , check ps to see zombie process <defunct>
	while(1)
		;
	
	printf("bye\n");//will never run
	exit(0);

}
