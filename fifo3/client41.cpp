#include "client.h"
#include <iostream>
 
#define TEST_FIFO "/tmp/client_fifo"
void UTIL_DeleteFile( const char *szFile )
{
	if( unlink( szFile ) == 0 )
	{	
		//UTIL_LogPrint( "deleted \"%s\"\n", szFile );
	}
	else
	{
#ifdef WIN32
		//UTIL_LogPrint( "error deleting \"%s\"\n", szFile );
#else
		//UTIL_LogPrint( "error deleting \"%s\" - %s\n", szFile, strerror( errno ) );
#endif
	}
}

bool UTIL_CheckFile( const char *szFile )
{
	// check if file exists

	FILE *pFile = NULL;

	if( ( pFile = fopen( szFile, "r" ) ) == NULL )
		return false;

	fclose( pFile );

	return true;
}


int client(OpType OT_In, int para1)
//int client(std::string grade , std::string hash)
{
	printf("[%s:%d]:%s()- #### - !!\n",__FILE__,__LINE__,__func__);
	int server_fifo_fd;
	int client_fifo_fd;
	int res;
	
	char client_fifo_name[NAME_SIZE];
	
	MessageClient MC1;
	MC1.client_pid = getpid();
	Message_Book MB;
	Message_Status MS;
	Message_LimitInfo ML;
	
	sprintf(client_fifo_name, CLIENT_FIFO_NAME, MC1.client_pid);

	//if (mkfifo(client_fifo_name, 0777) == -1)
	
//	if(UTIL_CheckFile(SERVER_FIFO_NAME))
//	{
//		UTIL_DeleteFile(TEST_FIFO);
//		cout <<"Delete "<< TEST_FIFO<< endl;
//	}


	if (mkfifo(TEST_FIFO, 0777) == -1)
	{
	    fprintf(stderr, "Sorry, create client fifo failure!\n");
	//    exit(EXIT_FAILURE);
	}
	    //BUG:: Using the following , when server_fifo exist but server has'nt start , it will keep waiting in open
	    //FIXME::use O_NONBLOCK to exit when server hasn't start
	//server_fifo_fd = open(SERVER_FIFO_NAME, O_WRONLY);
	server_fifo_fd = open( SERVER_FIFO_NAME, O_WRONLY/*|O_NONBLOCK*/ );
	if (server_fifo_fd == -1)
	{
	    fprintf(stderr, "Sorry, open server fifo failure!\n");
	    exit(EXIT_FAILURE);
	}    
	
// 	int OT = MC1.OT;
// 	OT = Status;
	
	switch(OT_In)
	{
	    case OT_Add:
	    {
		
		MC1.OT = OT_Add;
		printf("\n writing Add \n");
		write(server_fifo_fd, &MC1, sizeof(MC1));
	    }
	    break;
	    case OT_Book:
	    {
		 // the following should be in parameter
	    ////////////////////Construct the Message_Book Begin////////////////////
		
		//Construct the MessageClient		
		
		MC1.OT = OT_Book;		
		MB.MC = MC1;
		
		//Construct the CourseInfo
		CourseInfo CI1;			
		int itask = para1;//static
		
		switch(itask)
		{
		    case 0:
			strcpy( CI1.Hash, "4adc577ae4a06687ee31c70ecd3688dcc3277f9f");//ok Unit3
			strcpy( CI1.Name, "unit03 Fruit.rmvb");
			//CI1.Grade = 1;
			break;
		    case 1:
			strcpy( CI1.Hash, "979a7002197707306b64c9c36d3f228e9b6dcc94");//ok unicgi
			strcpy( CI1.Name, "unicgi");
			break;
		     case 2:
			strcpy( CI1.Hash, "67be647f4205ca28c9b805577524c7402fdd3d2c");//ok debugview
			strcpy( CI1.Name, "Dbgview.exe");
			break;
		     case 3:
			strcpy( CI1.Hash, "5c491fc742866e963160a2c20c58678bd98dae1f");//ok Example 3
			strcpy( CI1.Name, "Example Torrent 3");
			break;			
		     case 4:
			strcpy( CI1.Hash, "957d464049d3f8e820965ad9d028076088af8a67");//ok Example 1
			strcpy( CI1.Name, "Example Torrent 1");
			break;
		     default:
			strcpy( CI1.Hash, "d1f2fadcdf453222caf60cd1f61d09cc36949757");//ok Example 2
			strcpy( CI1.Name, "Example Torrent 2");
			break;
		}
		CI1.Grade = 3;				
		strcpy( CI1.Path, "/tmp/hdd/volumes/HDD/12/unit3");
		strcpy( CI1.ID, "123456789");
		//strcpy( CI1.Name, "How to learn math");
		CI1.Level = 12 ;
		MB.CI = CI1;
	
		////////////////////Construct the Message_Book Complete////////////////////
		printf("\n writing Book \n");
		write(server_fifo_fd, &MB, sizeof(MB));
	    }
		break;
	    case OT_Status:
	    {
		////////////////////Construct the Message_Status Begin////////////////////
		
		
		MC1.OT = OT_Status;
		MS.MC = MC1;
		JobInfoC JIC1;
		strcpy(JIC1.ID , "1");//this should be the course_id not the task_id		
		cout << endl << JIC1.ID << endl;
		MS.JIC = JIC1;
		////////////////////Construct the Message_Status Complete////////////////////
		printf("\n writing Status \n");
		write(server_fifo_fd, &MS, sizeof(MS));
	    }
		break;
	    case OT_LimitSpeed:
	    {
		////////////////////Construct the Message_LimitInfo Begin////////////////////
		 
		 
		 MC1.OT = OT_LimitSpeed;
		 ML.MC = MC1;
		 LimitInfo LI1;
		 LI1.DownloadSpeedLimitTo = 20;//20kB/s
		 LI1.UploadSpeedLimitTo = 10;//10kB/s
		 strcpy( LI1.ModuleName , "AV");
		 ML.LI = LI1;
		 
		 ////////////////////Construct the Message_LimitInfo Begin////////////////////
		 printf("\n writing Limit \n");
		 write(server_fifo_fd, &ML, sizeof(Message_LimitInfo));
	    }
		break;
	    default:
		break;	 
	
	}
//	client_fifo_fd = open(client_fifo_name, O_RDONLY);
	client_fifo_fd = open(TEST_FIFO, O_RDONLY);
	if (client_fifo_fd == -1)
	{
	    fprintf(stderr, "Sorry, client fifo open failure!\n");
	    exit(EXIT_FAILURE);
	}

	ResultInfo RI;
	memset( &RI, 0 , sizeof(RI));	
	
	switch(OT_In)
	{
	    case OT_Book:
	    {
		res = read(client_fifo_fd, &RI, sizeof(RI));
		std::cout<< "Result: " << RI.result << endl;
	    }
		break;
	    case OT_Status:
	    {	res = read(client_fifo_fd, &MS, sizeof(Message_Status));
		std::cout << "Receive pid : " << MS.MC.client_pid <<" Percent : " << MS.JIC.Percent << std::endl;
	    }
		break;
	    case OT_LimitSpeed:
	    {
		res = read(client_fifo_fd, &RI, sizeof(RI));
		std::cout<< "Result: " << RI.result << endl;
	    }
		break;
	    default:
	    {
		res = read(client_fifo_fd, &RI, sizeof(RI));
		std::cout<< "Result: " << RI.result << endl;
		
	    }
		break;	 
	
	}
    
// 	if (res > 0)
// 	{
// 	    std::cout << "Receive pid : " << RI.MC.client_pid <<" result : " << RI.result << std::endl;
// 	}

	close(client_fifo_fd);
	close(server_fifo_fd);
	unlink(client_fifo_name);
	printf("[%s:%d]:%s()- #### - !!\n",__FILE__,__LINE__,__func__);
	exit(EXIT_SUCCESS);
	//return SUCCEED;
}

