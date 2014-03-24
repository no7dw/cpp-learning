#include <stdlib.h>
#include  <iostream>
#include <stdio.h>
 
///@Summary: 将时间00：01：20.231转化到毫秒80231
	static int ToIntMillTime( char* time, double &second)
	{
		//printf("time in :%s\t",time);
		int i=0,j=0;

		char* tmp = time;
		char time_array[3][3];
		
		long  mill_sec[4];


		for(j=0;j<3;j++)
		{
			i=0;
			for(i=0;i<2;i++)
			{
				time_array[j][i]=*tmp;
				

				tmp++;
			}
			sprintf(&time_array[j][2],"\0");
			tmp++;

		}
		
		for(i=0;i<3;i++)
		{
			mill_sec[i]=atol(time_array[i]);
			//printf("\t%d %s \t",i,time_array[i]);
		}
		
		mill_sec[3] = atof(tmp);	//指向毫秒
		
		//printf("\t%d %s \t",i,tmp);
		//printf(" %ld \t",mill_sec[3]);
		
		second=(double)(mill_sec[0]*3600+mill_sec[1]*60+mill_sec[2]+0.001*mill_sec[3];//时分秒毫秒
		
		//printf("time out :%f\n",second);
		return 0;
		
	}	

int main(void)
{
	double d_time;
	char *c_time = "00:01:20.231";
	ToIntMillTime( c_time, d_time );
	printf("d_time = %f\n", d_time);
	return 0;
}
