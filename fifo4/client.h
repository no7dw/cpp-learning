#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <iostream>
#include <vector>

using namespace std;

#define SERVER_FIFO_NAME "/tmp/server_fifo"
// #define CLIENT_FIFO_NAME "/tmp/client_%d_fifo"
#define CLIENT_FIFO_NAME "/tmp/client_fifo"
#define CLIENT_TEST_DEAD_FIFO_NAME "/tmp/client_test_dead_fifo"

#define BUFFER_SIZE PIPE_BUF
#define MESSAGE_SIZE 20
#define NAME_SIZE 256


typedef enum {
	OT_Unkown = -1,
	OT_Add = 0,
	OT_Del,
	OT_Pause,
	OT_Start,	
	OT_Book,
	OT_UnBook,
	OT_Status,
	OT_LimitSpeed,	
	OT_Event_Download_Compelete,
	OT_FeedBack,
	OT_UnBook_But_NO_Del,
	OT_TEST_NOT_DEAD,
	OT_OpTypeNum
	
}OpType;//kind of event


typedef struct{
	pid_t client_pid;
	OpType OT;

}MessageClient;

typedef struct{

	char ID[10];
	char Path[100];
	char Hash[48];
	int Level;
	int Grade;
}CourseInfo;

typedef struct{
	MessageClient MC;
	CourseInfo CI;

}Message_Book;

typedef struct LimitInfo{
	
	char ModuleName[10];
	int DownloadSpeedLimitTo;
	int UploadSpeedLimitTo;

}LimitInfo;


typedef struct Message_LimitInfo
{
	MessageClient MC;
	LimitInfo LI;

}Message_LimitInfo;


 struct ResultInfo{
	MessageClient MC;	
	int result;
	ResultInfo()
	{
		memset( &MC, 0 , sizeof(MessageClient));
	}
};


