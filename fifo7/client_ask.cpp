#include "client.h"
#include "Util.h"
#define MAX_COMMUNICATE_TIMES 1

int main(int argc ,char **argv)
{
	int server_fifo_fd = -1;
	int client_fifo_fd = -1;

	int res;

	char client_fifo_name[NAME_SIZE];

	cout <<"Delete "<< CLIENT_ALL_FIFO_NAME ;
		
	Message_Status MS;
	MessageClient MC1;
	MC1.client_pid = getpid();
	MC1.OT = OT_Status;
	
	MS.MC = MC1;
	strcpy(MS.JIC.ID, "610106_pre"	);

	
	sprintf(client_fifo_name, "%s", "/tmp/client_fifo");
	printf(" starting 1: mkfifo client_fifo_name\n");
	if (mkfifo(client_fifo_name, 0666) == -1)	
	{
		fprintf(stderr, "Sorry, create client fifo failure ! may exist already \n");
//		exit(EXIT_FAILURE);
	}
	//BUG:: Using the following , when server_fifo exist but server has'nt start , it will keep waiting in open
	//FIXME::use O_NONBLOCK to exit when server hasn't start
	//server_fifo_fd = open(SERVER_FIFO_NAME, O_WRONLY);
	printf(" starting 2 open SERVER_FIFO_NAME \n");    
	server_fifo_fd = open( SERVER_FIFO_NAME, O_WRONLY/*|O_NONBLOCK*/);
	
	printf(" starting: after open\n");
	
	if (server_fifo_fd == -1)
	{
		fprintf(stderr, "Sorry, open server fifo failure!\n");
		exit(EXIT_FAILURE);
	}
	printf(" starting 3: write \n");

	    

//	for(int i=0; i<MAX_COMMUNICATE_TIMES; i++, MB.CI.Grade++)
	{
		sleep(1);
	//	printf("client %d sent hash = %s Grade = %d\n", MC1.client_pid, MB.CI.Hash, MB.CI.Grade);		
		write(server_fifo_fd, &MS, sizeof(Message_Status));
		
		printf(" starting 4: open client_fifo_name \n");
		if(client_fifo_fd==-1)
			client_fifo_fd = open(client_fifo_name, O_RDONLY);
		if (client_fifo_fd == -1)
		{
			fprintf(stderr, "Sorry, client fifo open failure!\n");
			exit(EXIT_FAILURE);
		}
		res = read(client_fifo_fd, &MS, sizeof(Message_Status));
		if (res > 0)
		{
		//	printf( "\nReceive pid = %d  OT = %d  result : = %d \n" , RI.MC.client_pid ,  RI.MC.OT ,RI.result );
			printf("serverM is not dead!\n");
			printf("\n%s %f%%  %f KB/s \n", MS.JIC.ID, MS.JIC.Percent, MS.JIC.DwRate);
		}/*
		res = read(client_fifo_fd, &RI, sizeof(ResultInfo));
		if (res > 0)
		{
			printf( "\n 2 Receive pid = %d  OT = %d  result : = %d \n" , RI.MC.client_pid ,  RI.MC.OT ,RI.result );
			printf(" 2 serverM is not dead!\n");
		}*/
		
	}
	
	printf(" starting 6: close  \n");
	close(client_fifo_fd);
	close(server_fifo_fd);
	//     unlink(client_fifo_name);

	exit(EXIT_SUCCESS);
}

