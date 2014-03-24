#include "client.h"
#include "Util.h"
int main()
{
	int server_fifo_fd = -1;
	int client_fifo_fd = -1;

	int res;
	char client_fifo_name[NAME_SIZE];

	MessageClient MC1;
	memset(&MC1, 0 , sizeof(MC1));
	printf("\n starting 1:\n");
	//    if(UTIL_CheckFile(SERVER_FIFO_NAME))
	{
		UTIL_DeleteFile(SERVER_FIFO_NAME);
		cout <<"Delete "<< SERVER_FIFO_NAME ;	
	}
	printf("\n starting 2: mkfifo SERVER_FIFO_NAME\n");
	if (mkfifo(SERVER_FIFO_NAME, 0666) == -1)
	{
		fprintf(stderr, "Sorry, create server fifo failure!\n");
		exit(EXIT_FAILURE);
	}
	printf("\n starting 3: open SERVER_FIFO_NAME\n");
	
	
	server_fifo_fd = open(SERVER_FIFO_NAME, O_RDONLY/*|O_NONBLOCK*/);
	if (server_fifo_fd == -1)
	{
		fprintf(stderr, "Sorry, server fifo open failure!\n");
		exit(EXIT_FAILURE);
	}
	printf("\n starting while:\n");
	while (1)
	{		
		ResultInfo RI;
		//First read Operation Type
		
		printf("\n starting 4: read server_fifo_fd MessageClient \n");
		if((res = read(server_fifo_fd, &MC1, sizeof(MessageClient))) > 0)
		{						
			CourseInfo CI;		
			int OT = MC1.OT;
			printf("OT = %d\t",OT);
			switch(OT)
			{
				case OT_Book:
					{
						printf("\n starting 5: read  server_fifo_fd CourseInfo \n");
						if((res = read( server_fifo_fd, &CI, sizeof(CourseInfo))) > 0)
						{
// 							sleep(1);//stand for do some post and get and annylyse														

							cout << "Got a book  Hash:" << CI.Hash <<" client " << MC1.client_pid << " Grade "<<CI.Grade  << endl;
						}
					}
					break;
				
				default:
					break;
			}
			
			fflush(stdout);
	
			sprintf(client_fifo_name, "%s", CLIENT_FIFO_NAME);
			if(client_fifo_fd == -1)
			{
				printf("\n open client_fifo_name \n");
				client_fifo_fd = open(client_fifo_name, O_WRONLY);
			}
			if (client_fifo_fd == -1)
			{
				printf("\n open again client_fifo_name \n");
				if(!UTIL_CheckFile(client_fifo_name))
				{
					printf("\n%s not exist \n" , client_fifo_name);				
					fprintf(stderr, "Sorry, client fifo open failure!\n");
					exit(EXIT_FAILURE);
				}
			}
			
			
			RI.result = 0;
			RI.MC.client_pid = MC1.client_pid;
			printf("write ResultInfo %d\t", OT);
			write(client_fifo_fd, &RI, sizeof(ResultInfo) );
			printf("write ResultInfo complete\n");
			fflush(stdout);
			
// 			close(server_fifo_fd);
		}
		/*
		 * IMPORTANT :
		 * 如果不想用sleep等的方法， 则需要close (server_fifo_fd), 再打开， 以达到 block read 的效果
		 * */
		else//keep try open
		{
			printf("in sleep res =%d\n", res);
			fflush(stdout);
			sleep(1);//need to sleep for a few second for it will make 100%cpu
		}
	}

	close(server_fifo_fd);
	//     unlink(SERVER_FIFO_NAME);
	exit(EXIT_SUCCESS);
}

