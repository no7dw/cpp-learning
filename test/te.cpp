#include <string.h>
#include <stdio.h>
#define MAX_USER 3
int main(void)
{
	char *cresult[MAX_USER] ;
//	memset(cresult, 0 ,sizeof(cresult) * MAX_USER);//默认设置NULL 不显示结果
	for(int iuser_index=0; iuser_index < MAX_USER; iuser_index++)
	{		
			printf("%d\n",iuser_index);		
			cresult[iuser_index] = NULL;
			
	}
	printf("end \n");		
}
