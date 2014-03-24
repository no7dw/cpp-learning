#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

//多少次没接收到信号
#define TIME_OUT_COUNT_TO_KILL 20 
//收信号间隔描述
#define WATCH_SLEEP_SECOND 2
//watchdog fifo
#define WATCH_FIFO "/tmp/watch_fifo"

int watch_fifo_fd = -1;
int g_unget_count = 0;
//杀死所有名为 serverM 的进程
int kill_it()
{

			FILE *fp;
			char *line = NULL;
			size_t len = 0;
			ssize_t read;

			system("pidof serverM > /tmp/serverM_pids");

			fp = fopen("/tmp/serverM_pids", "r");
			if (fp == NULL)
			exit(EXIT_FAILURE);

			char ce = ' ';

		//	kill them 
			while ((read = getdelim(&line, &len, ce , fp)) != -1) {
				if(len>0)
				{	
					char killcmd [100] = {0};
					sprintf( killcmd ,"kill -9 %s ", line );
					printf(" killcmd :  %s \n" , killcmd);
					system(killcmd);
					g_unget_count = 0;
				}
			}   
			free( line);
			fclose(fp);
			return 0;
}

int kill_process(const char *process_name)
{
	if(process_name!=NULL)
	{
		char killcmd [100] = {0};
		sprintf( killcmd ,"killall -9  %s ", process_name );
		printf(" killcmd :  %s \n" , killcmd);
		system(killcmd);
	}
}

//创建进程 启动 serverM
void* thread_server(void*)
{
	printf("in thread system \n");
	system("./serverM");
	printf("coming out of thread system \n");
	pthread_exit(0);
}

//结束 watchdog 本身的处理
void EndSys(int sign_no)
{
	if(sign_no == SIGQUIT )
	{
		printf("Got SIGQUIT\n");
	}
	else if(sign_no == SIGKILL )
	{
		printf("Got SIGKILL\n");
	}
	else if(sign_no == SIGTERM )
	{
		printf("Got SIGTERM\n");
	}
	
	close(watch_fifo_fd);
	unlink(WATCH_FIFO);	
	exit(1); 
}
//初始化 信号处理
int InitSys()
{
   
    signal(SIGQUIT, EndSys);
    signal(SIGKILL, EndSys);
    signal(SIGTERM, EndSys);
    
}

int main(void)
{
	system("pidof serverM > /tmp/serverM_pids");
	if (mkfifo(WATCH_FIFO, 0777) == -1)
	{
		fprintf(stderr, "Sorry, create WATCH_FIFO failure! may exist already\n");
	}
	watch_fifo_fd = open(WATCH_FIFO, O_RDONLY);
	if (watch_fifo_fd == -1)
	{
	    fprintf(stderr, "Sorry, client fifo open failure!\n");
	    exit(EXIT_FAILURE);
	}
	
	
	char cget[2] = {0};
	int res = 0;
	
	do
	{	
		res = read(watch_fifo_fd, &cget, sizeof(cget));
		if( res > 0 )
		{
			//printf("Bark: wow wow ~ dog : cget : %s \n reset g_unget_count = 0 \n", cget);
			g_unget_count = 0;
			continue;
		}
		else
		{
			sleep(WATCH_SLEEP_SECOND);
			g_unget_count++;
			if(g_unget_count>10)
				printf("Bark: watchdog_serverM did NOT receive a signal for  %d second * %d \n", WATCH_SLEEP_SECOND, g_unget_count );

		}
		if(g_unget_count > TIME_OUT_COUNT_TO_KILL)//need to restart
		{
		
	//		kill_it();
	//		kill_it();//kill twice	
			kill_process("serverM");		
			printf("sleeping for 10 second\n");
			sleep(10);
			printf("sleep end and restart serverM\n");
			
			pthread_t ptid;
			pthread_create(&ptid, NULL, thread_server, NULL);
		}
		sleep(2);
	}while(true);
	
	close(watch_fifo_fd);
	unlink(WATCH_FIFO);	
	exit(EXIT_SUCCESS);
}

