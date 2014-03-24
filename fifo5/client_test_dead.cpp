#include "client.h"
#include "Util.h"
#define MAX_COMMUNICATE_TIMES 1

int main(int argc ,char **argv)
{
	int server_fifo_fd = -1;
	int client_fifo_fd = -1;

	int res;

	char client_fifo_name[NAME_SIZE];

	UTIL_DeleteFile(CLIENT_TEST_DEAD_FIFO_NAME);
	cout <<"Delete "<< CLIENT_TEST_DEAD_FIFO_NAME ;
		
	Message_Book MB;
	//Construct the MessageClient
	MessageClient MC1;
	MC1.client_pid = getpid();
	MC1.OT = OT_TEST_NOT_DEAD;
	
	MB.MC = MC1;
	//Construct the CourseInfo
	CourseInfo CI1;
	
	if (argc>=2)
	{
		CI1.Grade = atoi(argv[1]);
		strcpy ( CI1.Hash ,argv[2] );
	}
	else
	{
		strcpy( CI1.Hash, "000000012");
		CI1.Grade = 1;		
	}
	
	strcpy( CI1.Path, "/tmp/hdd/volumes/HDD/12/unit3");
	strcpy( CI1.ID, "123456789");
	CI1.Level = 12 ;

	MB.CI = CI1;
	
	
	sprintf(client_fifo_name, "%s", CLIENT_TEST_DEAD_FIFO_NAME);
	printf(" starting 1: mkfifo client_fifo_name\n");
	if (mkfifo(client_fifo_name, 0666) == -1)	
	{
		fprintf(stderr, "Sorry, create client fifo failure!\n");
		exit(EXIT_FAILURE);
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

	    

	for(int i=0; i<MAX_COMMUNICATE_TIMES; i++, MB.CI.Grade++)
	{
		sleep(1);
		printf("client %d sent hash = %s Grade = %d\n", MC1.client_pid, MB.CI.Hash, MB.CI.Grade);		
		write(server_fifo_fd, &MB, sizeof(Message_Book));
		
		printf(" starting 4: open client_fifo_name \n");
		if(client_fifo_fd==-1)
			client_fifo_fd = open(client_fifo_name, O_RDONLY);
		if (client_fifo_fd == -1)
		{
			fprintf(stderr, "Sorry, client fifo open failure!\n");
			exit(EXIT_FAILURE);
		}
		ResultInfo RI;
		res = read(client_fifo_fd, &RI, sizeof(ResultInfo));
		if (res > 0)
		{
			printf( "\nReceive pid = %d  OT = %d  result : = %d \n" , RI.MC.client_pid ,  RI.MC.OT ,RI.result );
			printf("serverM is not dead!\n");
		}
		
	}
	
	printf(" starting 6: close  \n");
	close(client_fifo_fd);
	close(server_fifo_fd);
	//     unlink(client_fifo_name);

	exit(EXIT_SUCCESS);
}

