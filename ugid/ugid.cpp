#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("uid = %d ,gid = %d , getpid = %d \n" ,getuid(), getgid(),getpid());
	sleep(10);	
}
