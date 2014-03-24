#include "client.h"
#include "Util.h"
int main()
{
    int server_fifo_fd;
    int client_fifo_fd;

    int res;
    char client_fifo_name[NAME_SIZE];

    message msg;
	LimitInfo LI;
    CourseInfo CI;
	OpType OT;
	//BUG:: Using the following ,when server_fifo exist, it will keep waiting when use CheckFile ,may be it is in using ,and was blocked .
	//FIXME:: Don't CheckFile just DeleteFile
//    if(UTIL_CheckFile(SERVER_FIFO_NAME))
	{
		UTIL_DeleteFile(SERVER_FIFO_NAME);
		cout <<"Delete "<< SERVER_FIFO_NAME << endl;
	
	}

    if (mkfifo(SERVER_FIFO_NAME, 0777) == -1)
    {
        fprintf(stderr, "Sorry, create server fifo failure!\n");
        exit(EXIT_FAILURE);
    }

    server_fifo_fd = open(SERVER_FIFO_NAME, O_RDONLY);
    if (server_fifo_fd == -1)
    {
        fprintf(stderr, "Sorry, server fifo open failure!\n");
        exit(EXIT_FAILURE);
    }

//    sleep(5);

//   while ((res = read(server_fifo_fd, &CI, sizeof(CI))) > 0)
   int count =0;
   
   while (1)
   {
	//First read Operation Type
    	if((res = read(server_fifo_fd, &msg, sizeof(msg))) > 0)
	{
		
		//CI.str="YYY";
		
		sprintf(client_fifo_name, CLIENT_FIFO_NAME, msg.client_pid);
		client_fifo_fd = open(client_fifo_name, O_WRONLY);
		if (client_fifo_fd == -1)
		{
			fprintf(stderr, "Sorry, client fifo open failure!\n");
			exit(EXIT_FAILURE);
		}

	//        write(client_fifo_fd, &CI, sizeof(CI));
		ResultInfo RI;
//		RI.client_pid = msg.client_pid;
		//RI.result = SUCCEED;
		RI.result = SUCCEED;

		int OT = msg.ot;
//		int grade = CI.Grade;

		string strHash ;
		strHash.assign(CI.Hash, strlen(CI.Hash));
		switch(OT)
		{
			case Book:
				{
					if((res = read(server_fifo_fd, &CI, sizeof(CI))) > 0)
					{
						RI.client_pid = CI.client_pid;
						//do the book thing
						string strHash ;
						strHash.assign(CI.Hash, strlen(CI.Hash));
						Vhash1.push_back(strHash);
						cout << "Got a book  :" << CI.Hash << CI.client_pid << endl;
					}
				}
				break;
			
			case LimitSpeed:
				{

					if((res = read(server_fifo_fd, &LI, sizeof(LI))) > 0)
					{
						RI.client_pid = LI.client_pid;
						//do the Limit thing
						cout << "LI.DownloadSpeedLimitTo :" << LI.DownloadSpeedLimitTo << endl;
					}
				}
				break;

			case Status:
				{
				//Vhash3.push_back(strHash);
				//cout << "Vhash3 size " << Vhash3.size() << endl;
				}
				break;
			default:
				break;
		}
		cout << count++ << endl;
		
		write(client_fifo_fd, &RI, sizeof(RI));
		close(client_fifo_fd);
	}
	else//keep try open
	{
		//sleep(1);
	}
    }

    close(server_fifo_fd);
    unlink(SERVER_FIFO_NAME);
    exit(EXIT_SUCCESS);
}

