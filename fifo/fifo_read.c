#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>

#define FIFOMODE (O_CREAT|O_RDWR|O_NONBLOCK)
//#define OPENMODE (O_WRONLY|O_NONBLOCK)
#define OPENMODE (O_RDONLY|O_NONBLOCK)
#define FIFO_SERVER "myfifo"
using namespace std;

typedef struct{
	int i1;
	bool b2;
	string s3;
}Comp;

int main(int argc ,char **argv)
{
	int fd;
	//char buf[100];
	Comp buf;
/*
	buf.i1=1;
	buf.b2=false;
	buf.s3="abcdefg";
*/	
	int readnum;
	if(mkfifo(FIFO_SERVER,FIFOMODE)<0 && (errno!=EEXIST))
	{
		printf("cannot create fifoserver \n");
		exit(1);
	}
	printf("Preaparing for read bytes ... \n");


	if((fd=open(FIFO_SERVER,OPENMODE))<0)
	{
		perror("open");
		exit(1);
	}

	while(1)
	{
		bzero(buf,sizeof(buf));
		if( readnum = read (fd,buf,sizeof(buf) ) ){
			if(errno==EAGAIN){
				printf("no data yet\n");
			}
		}
		if(readnum!=0){
			buf[readnum]='\0';
			printf("read %s from FIFO_SERVER\n",buf);
		}
		sleep(1);
	}
	return 0;

}
