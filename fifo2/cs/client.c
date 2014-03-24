#include "client.h"

int main()
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

    server_fifo_fd = open(SERVER_FIFO_NAME, O_WRONLY);
    if (server_fifo_fd == -1)
    {
        fprintf(stderr, "Sorry, open server fifo failure!\n");
        exit(EXIT_FAILURE);
    }

//    sprintf(CI.data, "%d", msg.client_pid);
	    
	strcpy( CI.ID, "000000012");
	strcpy( CI.Path, "/tmp/hdd/volumes/HDD/12/unit3");
	strcpy( CI.Hash, "01234567890123456789");
	CI.Level = 12 ;
	CI.OT = Add;
	

//    printf("%d sent %s \n", msg.client_pid, msg.data);
 //   write(server_fifo_fd, &msg, sizeof(msg));
    printf("%d sent %s \n", CI.client_pid, CI.Path);
    write(server_fifo_fd, &CI, sizeof(CI));

    client_fifo_fd = open(client_fifo_name, O_RDONLY);
    if (client_fifo_fd == -1)
    {
        fprintf(stderr, "Sorry, client fifo open failure!\n");
        exit(EXIT_FAILURE);
    }
    res = read(client_fifo_fd, &CI, sizeof(CI));
    if (res > 0)
    {
        printf("received:%d %s\n", CI.client_pid, CI.Path);
    }

    close(client_fifo_fd);
    close(server_fifo_fd);
    unlink(client_fifo_name);

    exit(EXIT_SUCCESS);
}

