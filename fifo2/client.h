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
#define CLIENT_ALL_FIFO_NAME "/tmp/client_all_fifo"
#define CLIENT_FIFO_NAME "/tmp/client_%d_fifo"

#define BUFFER_SIZE PIPE_BUF
#define MESSAGE_SIZE 20
#define NAME_SIZE 256


typedef enum {
	Add,
	Remove,
	Pause,
	Status,
	LimitSpeed,
	Book

}OpType;

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

typedef enum{
	FAIL = -1 ,
	SUCCEED = 0 
}Result;

typedef struct ResultInfo{
	MessageClient MC;	
	Result result;

}ResultInfo;

vector<string> Vhash1;
vector<string> Vhash2;
vector<string> Vhash3;

