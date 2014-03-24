#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define WATCH_FIFO "/tmp/watch_fifo"

void CommunicateToWatchdog()
{
	int watchdog_fifo_fd = open(WATCH_FIFO, O_WRONLY);
			
	if (watchdog_fifo_fd == -1)
	{
		fprintf(stderr, "Sorry, WATCH_FIFO open failure! \n");//BUG 1::always go to this  
		return ;
	}	
	char cwrite[2] = {0};
	strcpy(cwrite, "a");
	write(watchdog_fifo_fd, &cwrite, sizeof(char)*strlen(cwrite));
	printf("feed dog : %s !\n",cwrite);
	close(watchdog_fifo_fd);
}

int main(void)
{
	CommunicateToWatchdog();
}
