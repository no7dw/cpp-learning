#include "client.h"

int main(int argc ,char **argv)
{
    int server_fifo_fd;
    int client_fifo_fd;

    int res;

    char client_fifo_name[NAME_SIZE];

//    message msg;
	CourseInfo CI;
	LimitInfo LI;

    LI.client_pid = getpid();

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
		LI.DownloadSpeedLimitTo = atoi(argv[1]);
		LI.UploadSpeedLimitTo = atoi(argv[2]);
	}
	else
	{

		LI.DownloadSpeedLimitTo = 20;
		LI.UploadSpeedLimitTo = 10;
	}
	
	strcpy( LI.ModuleName , "AV");

	message msg;
	msg.client_pid = LI.client_pid;
	msg.ot = LimitSpeed ;
//	CI.str = "xxx";

//    printf("%d sent %s \n", msg.client_pid, msg.data);
 //   write(server_fifo_fd, &msg, sizeof(msg));
    printf("%d sent %s \n", LI.client_pid, LI.ModuleName );
    write(server_fifo_fd, &msg, sizeof(msg));
    write(server_fifo_fd, &LI, sizeof(LI));//Program received signal SIGPIPE, Broken pipe. (when first time call this)

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
        cout << "Receive pid : " << RI.client_pid <<" result : " << RI.result << endl;
	//printf("received:%d %s\n", CI.client_pid, CI.str);
  //      cout << "receive " << CI.client_pid << " " << CI.str << endl;
    }

    close(client_fifo_fd);
    close(server_fifo_fd);
    unlink(client_fifo_name);

    exit(EXIT_SUCCESS);
}

