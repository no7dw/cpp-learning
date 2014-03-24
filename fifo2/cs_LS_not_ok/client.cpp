#include "client.h"

int main(int argc ,char **argv)
{
    int server_fifo_fd;
    int client_fifo_fd;

    int res;

    char client_fifo_name[NAME_SIZE];

//    message msg;
	CourseInfo CI;

    CI.client_pid = getpid();
    sprintf(client_fifo_name, CLIENT_FIFO_NAME, CI.client_pid);

    if (mkfifo(client_fifo_name, 0777) == -1)
    {
        fprintf(stderr, "Sorry, create client fifo failure!\n");
        exit(EXIT_FAILURE);
    }
	//BUG:: Using the following , when server_fifo exist but server has'nt start , it will keep waiting in open
	//FIXME::use O_NONBLOCK to exit when server hasn't start
    //server_fifo_fd = open(SERVER_FIFO_NAME, O_WRONLY);
    server_fifo_fd = open(SERVER_FIFO_NAME, O_WRONLY|O_NONBLOCK);
    if (server_fifo_fd == -1)
    {
        fprintf(stderr, "Sorry, open server fifo failure!\n");
        exit(EXIT_FAILURE);
    }

//    sprintf(CI.data, "%d", msg.client_pid);
	    
	if (argc>=2)
	{
		CI.Grade = atoi(argv[1]);
		strcpy ( CI.Hash ,argv[2] );
	}
	else
	{
		strcpy( CI.Hash, "000000012");
		CI.Grade = 1;		
	}
	
	strcpy( CI.Path, "/tmp/hdd/volumes/HDD/12/unit3");
	strcpy( CI.ID, "123456789");
	CI.Level = 12 ;
	CI.OT =Book; 
	
	message msg;
	msg.client_pid = CI.client_pid;
	msg.ot = Book;
//	CI.str = "xxx";

//    printf("%d sent %s \n", msg.client_pid, msg.data);
 //   write(server_fifo_fd, &msg, sizeof(msg));
    printf("%d sent %s \n", CI.client_pid, CI.Path);
    write(server_fifo_fd, &msg, sizeof(msg));
    write(server_fifo_fd, &CI, sizeof(CI));//Program received signal SIGPIPE, Broken pipe. (when first time call this)

    client_fifo_fd = open(client_fifo_name, O_RDONLY);
    if (client_fifo_fd == -1)
    {
        fprintf(stderr, "Sorry, client fifo open failure!\n");
        exit(EXIT_FAILURE);
    }

//    res = read(client_fifo_fd, &CI, sizeof(CI));
	ResultInfo RI;
	memset( &RI, 0 , sizeof(RI));
    res = read(client_fifo_fd, &RI, sizeof(RI));
    if (res > 0)
    {
        printf("received:%d %s\n", CI.client_pid, CI.Path);
        cout << "Receive pid : " << RI.client_pid <<" result : " << RI.result << endl;
	//printf("received:%d %s\n", CI.client_pid, CI.str);
  //      cout << "receive " << CI.client_pid << " " << CI.str << endl;
    }

    close(client_fifo_fd);
    close(server_fifo_fd);
    unlink(client_fifo_name);

    exit(EXIT_SUCCESS);
}

