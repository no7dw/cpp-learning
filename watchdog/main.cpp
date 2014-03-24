#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define WATCH_FIFO "/tmp/watch_fifo"


int main(void)
{
	system("pidof serverM > /tmp/serverM_pids");
	if (mkfifo(WATCH_FIFO, 0777) == -1)
	{
		fprintf(stderr, "Sorry, create WATCH_FIFO failure! may exist already\n");
//		exit(EXIT_FAILURE);
	}
	int watch_fifo_fd = open(WATCH_FIFO, O_RDONLY);
	if (watch_fifo_fd == -1)
	{
	    fprintf(stderr, "Sorry, client fifo open failure!\n");
	    exit(EXIT_FAILURE);
	}
	//string strpids = UTIL_ReadFile("/tmp/serverM_pids");
	
	char cget[2] = {0};
	int res = 0;
	int unget_count = 0;
	do
	{	
		res = read(watch_fifo_fd, &cget, sizeof(char)*strlen(cget));
		if( res > 0 )
		{
			printf("wow wow ~ dog : cget : %s \n reset unget_count = 0 ", cget);
			unget_count = 0;
			continue;
		}
		else
		{
			sleep(1);
			unget_count++;
			printf("watchdog for serverM did NOT receive a signal for : %d \n", unget_count);
		}
		if(unget_count > 40)//need to restart
		{
			
			FILE *fp;
			char *line = NULL;
			size_t len = 0;
			ssize_t read;

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
					printf("1 killcmd :  %s \n" , killcmd);
					system(killcmd);
				}
			}   

		//	kill twice
			system("pidof serverM > /tmp/serverM_pids");

			while ((read = getdelim(&line, &len, ce , fp)) != -1) {
			
				if(len>0)
				{	
					char killcmd [100] = {0};
					sprintf( killcmd ,"kill -9 %s ", line );
					printf("2 killcmd :  %s \n" , killcmd);
					system(killcmd);
				}
			}   


			free(line);
			printf("sleeping for 30 second\n");
			sleep(30);
			printf("sleep end and restart serverM\n");
			system("serverM");//restart
		}
	}while(true);
	
	close(watch_fifo_fd);
	unlink(WATCH_FIFO);
	exit(EXIT_SUCCESS);
}

