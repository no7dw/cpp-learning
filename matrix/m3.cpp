#include "stdio.h"
#define MAX_USER_COUNT 3
#define BUFFER_PER_COUNT_TS 3
#define MAX_TIME_BUFER 300
void record(char *p[] ,int size);
int main(void)
{
	char *p[3][3];
	for(int i = 0;i <3 ; i++)
	{
		for(int j = 0;j <3 ; j++)
		{
			p[i][j] = new char[300];
		}
	}
	


}
