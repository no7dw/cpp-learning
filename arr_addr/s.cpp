#include <stdio.h>
#include <stdlib.h>

//int ar( int *ar_size , char *ar_buff[3], int *result);
int ar(const int *ar_size, char **ar_buff, int *result);
int main(void)
{
		int size[3] = {10,20,30};
		char *Aar_buf[3];
		for(int i = 0; i < 3 ; i++)
		{
			Aar_buf[i] = new char[200];
			sprintf(Aar_buf[i],"%d%d%d", i, i+1,i+2);
		}
		int result[3] = {0,0,0};
		
		ar( size, Aar_buf, result);
		for(int i = 0; i < 3 ; i++)
		{			
			printf("result[%d] = %d \n", i,result[i]  );			
		}
}
int ar(const int *ar_size, char **ar_buff, int *result)
{
	
	for(int i = 0; i < 3 ; i++)
	{
		result[i] = i;
		printf("size = %d  \t buf = %s\n",  ar_size[i] ,ar_buff[i] );		
	}
}
/*
int ar( int *ar_size ,const char *ar_buff[3], int *result)
{
	for(int i = 0; i < 3 ; i++)
	{
		(result[i]) = i;
		printf("size  =%d \t buf = %s \t result = %d ", ar_size[i], ar_buff[i], result[i] );
		
	}
}*/