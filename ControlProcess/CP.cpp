#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define MAXLINE 1000

static void sig_int( int );

int main(int argc , char **argv)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
	
	if((signal(SIGINT , sig_int) == SIG_ERR ))
	{
		printf("signal error \n");
		return 0;
	}
	
	printf("%%");
	while(fgets(buf, MAXLINE, stdin)!= NULL)
	{
		if((buf[strlen(buf)-1]) =='\n')
		{
			buf[strlen(buf)-1] = 0;
		}

		if((pid=fork() < 0)) 
		{
			printf("fork error");
			return 0;
		}
		else if( pid ==0 ) //child
		{
			execlp(buf,buf,(char *)0 );
			printf("can't execute : %s ", buf);
			return 0;
		}
		
		//parent
		if(( pid = waitpid( pid , &status , 0 )<0))
		{
			printf("waitpid error , status = %d ", status);
			return 0;
		}
		printf("%%");
	}
	return 1;
}

void sig_int(int signo)
{
	printf("\n signo = %d\n",signo );
	printf("interrupt \n");
}
