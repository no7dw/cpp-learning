#include "w.h"

 char BNBT_SERVER_IP[16];
 char BNBT_SERVER_PORT[5];

int main(int argc , char **argv)
{
	char hash[41]="c0ae6dddcb7ba83f2d9b1b2be0ad017c58e3530b";
	strcpy(BNBT_SERVER_IP, "192.168.2.9");
	strcpy(BNBT_SERVER_PORT, "6969");
	for(int i=0; i<10 ; i++)
	{
		printf("========== task NO:%d ========\n",i);
		TaskControl::Task_Add(hash);
	}
	printf("compelete\n");
}

