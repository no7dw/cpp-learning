#include "client.h"

int main(int argc ,char **argv)
{
    int server_fifo_fd;
    int client_fifo_fd;

    int res;

    char client_fifo_name[NAME_SIZE];

	Message_Book MB;
	//Construct the MessageClient
	MessageClient MC1;
	MC1.client_pid = getpid();
	MC1.OT = Book;
	
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
	
    sprintf(client_fifo_name, CLIENT_FIFO_NAME, MC1.client_pid);

    if (mkfifo(client_fifo_name, 0777) == -1)
    {
        fprintf(stderr, "Sorry, create client fifo failure!\n");
        exit(EXIT_FAILURE);
    }
	//BUG:: Using the following , when server_fifo exist but server has'nt start , it will keep waiting in open
	//FIXME::use O_NONBLOCK to exit when server hasn't start
    //server_fifo_fd = open(SERVER_FIFO_NAME, O_WRONLY);
    server_fifo_fd = open( SERVER_FIFO_NAME, O_WRONLY|O_NONBLOCK);
    if (server_fifo_fd == -1)
    {
        fprintf(stderr, "Sorry, open server fifo failure!\n");
        exit(EXIT_FAILURE);
    }

//    sprintf(CI.data, "%d", msg.client_pid);
	    

    printf("%d sent %s \n", MC1.client_pid, CI1.Hash);
    write(server_fifo_fd, &MB, sizeof(MB));

    client_fifo_fd = open(client_fifo_name, O_RDONLY);
    if (client_fifo_fd == -1)
    {
        fprintf(stderr, "Sorry, client fifo open failure!\n");
        exit(EXIT_FAILURE);
    }

	ResultInfo RI;
	memset( &RI, 0 , sizeof(RI));
    res = read(client_fifo_fd, &RI, sizeof(RI));
    if (res > 0)
    {
        cout << "Receive pid : " << RI.MC.client_pid <<" result : " << RI.result << endl;
    }

    close(client_fifo_fd);
    close(server_fifo_fd);
    unlink(client_fifo_name);

    exit(EXIT_SUCCESS);
}

