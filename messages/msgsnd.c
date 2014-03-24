#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 112

//using namespace std;

typedef enum{
	BookResource,
	CancelBookResource,
	AskForStatus,
	StartTask,
	PauseTask,
	DelTask,
	SpeedControl,
	LimitDownloadCount
	
}EXMSG_TYPE;

struct message{
	long msg_type;
	char msg_text[BUFFER_SIZE];
};

struct CompostStruct{
	int i1;
	bool b2;
	//string s3;
};

int main()
{
	int qid;
	key_t key;
	struct message msg;
	
	if((key=ftok(".",'a'))==-1)
	{
		perror("ftok");
		exit(1);
	}

	if((qid=msgget(key,IPC_CREAT|0666))==-1)
	{
		perror("msgget");
		exit(1);
	}

	printf("Open queue %d\n",qid);
	
	struct CompostStruct CS;
	CS.i1=1;
	CS.b2=false;
	//CS.s3="abcdefg";

	while(1)
	{
		printf("Enter some message to the queue:");
/*
		if((fgets(msg.msg_text,BUFFER_SIZE,stdin))==NULL)
		{
			puts("No message");
			exit(1);
		}
*/
		msg.msg_text = (char*)CS;
//		msg.msg_type=getpid();
		msg.msg_type=AskForStatus ;
		
		if((msgsnd(qid,&msg,strlen(msg.msg_text),0))<0)
		{
			perror("message posted");
			exit(1);
		}

		if(strncmp(msg.msg_text,"quit",4)==0)
		{
			break;
		}

	}
	exit(0);
}
