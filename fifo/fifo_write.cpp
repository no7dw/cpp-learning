#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
//#include <fstream>
#include <iostream>
using namespace std;

#define FIFOMODE (O_CREAT|O_RDWR|O_NONBLOCK)
#define FIFO_SERVER "/tmp/myfifo"
//#define OPENMODE (O_WRONLY|O_NONBLOCK)
#define OPENMODE (O_WRONLY|O_NONBLOCK)

typedef struct{
        int i1;
        bool b2;
//        string s3;
	char s3[100];
	char s4[10];
}Comp;


int main(int argc ,char **argv)
{
	int fd;
	int nwrite;

        Comp buf,*pbuf;
        pbuf=&buf;

        buf.i1=2;
        buf.b2=true;
        //buf.s3="abcdefg";
        strcpy(buf.s3, "abcdefghijklmnopqrstuvwxyz");
        strcpy(buf.s4, "012345678");

	if(mkfifo(FIFO_SERVER,FIFOMODE)<0 && (errno!=EEXIST))
        {
                printf("cannot create fifoserver \n");
                exit(1);
        }
 
	if((fd=open(FIFO_SERVER,OPENMODE))<0)
	{
		perror("open");
		exit(1);
	}
/*
	if(argc==1)
	{
		printf("please send something\n");
		exit(1);
	}
*/
	if ( nwrite = write(fd,  pbuf , sizeof(buf) ) )
	{

		if(errno==EAGAIN)
		{
			printf("the fifo has not been read yet.try again\n");
			exit(1);
		}
		else
		{
//			printf("write %s to fifo\n",argv[1]);
		cout << "write " << buf.i1 << " " << buf.b2 <<" " << buf.s3 << " "<< buf.s4 << endl;
		}		
		return 0;
		
	}

}
