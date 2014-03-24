#include "client.h"

int main(int argc ,char **argv)
{
    int server_fifo_fd;
    int client_fifo_fd;

    int res;

    char client_fifo_name[NAME_SIZE];

	Message_LimitInfo ML;
	//Construct the MessageClient
	MessageClient MC1;
	MC1.client_pid = getpid();
	MC1.OT = LimitSpeed;
	
	ML.MC = MC1;
	//Construct the CourseInfo
	LimitInfo LI1;
	
	if (argc>=2)
	{
		LI1.DownloadSpeedLimitTo = atoi(argv[1]);
		LI1.UploadSpeedLimitTo = atoi(argv[2]);
	}
	else
	{
		LI1.DownloadSpeedLimitTo = 20;
		LI1.UploadSpeedLimitTo = 10;
	}
	
	strcpy( LI1.ModuleName , "AV");
	ML.LI = LI1;
	
    sprintf(client_fifo_name, CLIENT_FIFO_NAME, MC1.client_pid);

    if (mkfifo(client_fifo_name, 0777) == -1)
    {
        fprintf(stderr, "Sorry, create client fifo failure!\n");
        exit(EXIT_FAILURE);
    }

    server_fifo_fd = open( SERVER_FIFO_NAME, O_WRONLY|O_NONBLOCK);
    if (server_fifo_fd == -1)
    {
        fprintf(stderr, "Sorry, open server fifo failure!\n");
        exit(EXIT_FAILURE);
    }


    printf("%d sent %s \n", MC1.client_pid, LI1.ModuleName);
    write( server_fifo_fd, &ML, sizeof(ML));

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

