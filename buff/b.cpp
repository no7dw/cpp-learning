#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char buff2[4 * 16000 * 16 /8];
	printf("##################  sizeof(buff2)= %d#################\n",sizeof(buff2));

	char buff[3][4 * 16000 * 16 /8];
	memset(buff,0,sizeof(buff));
	
        printf("##################  sizeof(buff)= %d#################\n",sizeof(buff));
        printf("##################  sizeof(buff)0= %d#################\n",sizeof(buff[0]));
        printf("##################  sizeof(buff)1= %d#################\n",sizeof(buff[1]));
        printf("##################  sizeof(buff)2= %d#################\n",sizeof(buff[2]));

	printf("##################  address(buff)0= %x#################\n",&buff[0]);
	printf("##################  address(buff)1= %x#################\n",&buff[1]);
	printf("##################  address(buff)2= %x#################\n",&buff[2]);
        
	printf("##################  len(buff)= %d#################\n",sizeof(buff)/sizeof(buff[0]));
        return 1;
}
