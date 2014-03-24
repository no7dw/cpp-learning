#include <unistd.h>
#include <stdio.h>
#include "client.h"
#include <string.h>

int main(int argc , char **argv )
{

	if(argc<2)
	{
		printf("Usage: client Book/Add/Status\n");
		return -1;
	}
/*
    pid_t pid;
    if((pid=fork()) < 0)
	return -1;
    else if( pid == 0 )	//child
    {
    */
	if(strcasecmp("Book",argv[1] )==0)
	{
		printf("\nclient(Book)\n");
		client(OT_Book,atoi(argv[2]));
	}
	else if(strcasecmp("UnBook",argv[1] )==0)
	{
		printf("\nclient(UnBook)\n");
		client(OT_UnBook,atoi(argv[2]));
	}
	else if(strcasecmp("Add",argv[1] )==0)
	{
		printf("\nclient(Add)\n");
		client(OT_Add);
	}
	else if(strcasecmp("Status",argv[1] )==0)
	{
		printf("\nclient(Status)\n");
		client(OT_Status, atoi(argv[2]));
	}
	else if(strcasecmp("LimitSpeed",argv[1] )==0)
	{
		printf("\nclient(LimitSpeed)\n");
		client(OT_LimitSpeed);
	}
	else
		printf("none");
/*
	
    }
    else	//parent
    {
	    return 0;
    }
*/

}
