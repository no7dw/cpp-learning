#include "client.h"
#include "Util.h"
int main()
{
    int server_fifo_fd;
    int client_fifo_fd;

    int res;
    char client_fifo_name[NAME_SIZE];

	MessageClient MC1;
	memset(&MC1, 0 , sizeof(MC1));

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
    	if((res = read(server_fifo_fd, &MC1, sizeof(MC1))) > 0)
	{
		
		//CI.str="YYY";

		ResultInfo RI;
		RI.result = SUCCEED;

		RI.MC.client_pid = MC1.client_pid;
		CourseInfo CI;
		LimitInfo LI;
		int OT = MC1.OT;

		switch(OT)
		{
			case Book:
				{
					if((res = read( server_fifo_fd, &CI, sizeof(CI))) > 0)
					{
						//sleep(4);//stand for do some post and get and annylyse

						//do the book thing
						string strHash ;
						strHash.assign(CI.Hash, strlen(CI.Hash));
						Vhash1.push_back(strHash);

						//sleep(4);//stand for do some post and get and analyse

						cout << "Got a book  :" << CI.Hash <<" " << MC1.client_pid << endl;
					}
				}
				break;
			
			case LimitSpeed:
				{

					if((res = read(server_fifo_fd, &LI, sizeof(LI))) > 0)
					{
						//do the Limit thing
						//sleep(4);//stand for do some post and get and annylyse

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
		
		sprintf(client_fifo_name, CLIENT_FIFO_NAME, MC1.client_pid);
		client_fifo_fd = open(client_fifo_name, O_WRONLY);
		if (client_fifo_fd == -1)
		{
			fprintf(stderr, "Sorry, client fifo open failure!\n");
			exit(EXIT_FAILURE);
		}
		write(client_fifo_fd, &RI, sizeof(RI));
		close(client_fifo_fd);
	}
	else//keep try open
	{
		sleep(1);//need to sleep for a few second for it will make 100%cpu
	}
    }

    close(server_fifo_fd);
    unlink(SERVER_FIFO_NAME);
    exit(EXIT_SUCCESS);
}

