#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//3*4*200

int main(void)
{
	char ***buf = new char**[3]; 
	int index,index_sec;
	int col0 =3, col1 =4, col_sindexze =200;

	for(index = 0; index< col0; index++)
	{
		buf[index] = new char*[index];
		printf("new buf[%d]\n",index);
		for(index_sec = 0; index_sec< col1; index_sec++)
		{
			buf[index][index_sec] = new char[col_sindexze];
			printf("new buf[%d][%d]\n", index ,index_sec);
		}
	}
	
		
	for(index = 0;index< col0 ; index++)
	{
		for(index_sec = 0;index_sec< col1 ; index_sec++)
		{
			printf("delete buf[%d][%d]\n", index ,index_sec);			
			fflush(stdout);
			sleep(1);
			delete[] buf[index][index_sec];
			buf[index][index_sec] = NULL;
			
		}
		printf("delete buf[%d]\n", index );
		fflush(stdout);
		sleep(1);
		delete[] buf[index];
		buf[index] = NULL;

	}
	printf("delete buf\n"  );
	fflush(stdout);
	sleep(1);
	delete[] buf;
	buf = NULL;
  	return 0;
}
