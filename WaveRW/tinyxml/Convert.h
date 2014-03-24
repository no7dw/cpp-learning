// @Function: Convert 
// 
#ifndef __CONVERT_H
#define __CONVERT_H

#include <stdlib.h>
#include  <iostream> 
#include <string.h>
#define FRAME 25

using namespace std;

class Convert
{
private:
	
public:
	Convert();
	~Convert();
	//Convert scond and frameIndex  to  Char* Time "hh:mm:ss.ff" 
	//static char *ToCharTime(long second,int frameIndex);
	static string ToCharTime(long second,int frameIndex)
	{
		int hour , minute ,lastsecond ;
		hour =(int) second / 3600 ;
		minute =(int) (second-hour*3600) /60 ;
		
		lastsecond = (int)second - (hour*3600 + minute*60) ;
		
		char Chour[3] , Cminute[3] , CSecond[3] , CframeIndex[4];
		
		memset(Chour, 0, sizeof(char)*3);
		memset(Cminute, 0, sizeof(char)*3);
		memset(CSecond, 0, sizeof(char)*3);
		memset(CframeIndex, 0, sizeof(char)*4);
		

		int mms =(int)frameIndex*1000/FRAME;
// 		printf("mms:%d,frameIndex:%d\n",mms,frameIndex);

		if (hour<10)
			sprintf(Chour,"0%d",hour);//补0
		else
			sprintf(Chour,"%d",hour);
		if (minute<10)
			sprintf(Cminute,"0%d",minute);//补0
		else
			sprintf(Cminute,"%d",minute);
		if (lastsecond<10)
			sprintf(CSecond,"0%d",lastsecond);//补0
		else
			sprintf(CSecond,"%d",lastsecond);
		if (mms<10)		
			sprintf(CframeIndex,"00%d",mms);//补0
		else if(mms<100)
			sprintf(CframeIndex,"0%d",mms);
		else
			sprintf(CframeIndex,"%d",mms);
		
		
		
		char Result[13];
		memset(Result, 0, sizeof(char)*13);
		strcat(Result , Chour);
		strcat(Result , ":");
		strcat(Result , Cminute);
		strcat(Result , ":");
		strcat(Result , CSecond);
		strcat(Result , ".");
		strcat(Result , CframeIndex);
		
		string string1;
		string1.assign(Result,strlen(Result));
		return string1;
	};

	static int ToIntTime( char* time,long &second, int &frameIndex)
	{
		int i=0,j=0;

		char* tmp = time;
		char tmp2[3][3];
		char *SecondInFrame;
		long  tmp3[4];


		for(j=0;j<3;j++)
		{
			i=0;
			for(i=0;i<2;i++)
			{
				tmp2[j][i]=*tmp;

				tmp++;
			}
			sprintf(&tmp2[j][2],"\0");
			tmp++;

		}
		SecondInFrame=tmp;
		for(i=0;i<3;i++)
		{
			tmp3[i]=atol(tmp2[i]);

		}
		tmp3[3]=atol(SecondInFrame);

		second=tmp3[0]*3600+tmp3[1]*60+tmp3[2];

		frameIndex=(int)tmp3[3]*FRAME/1000;

		return 0;
		
	}
	
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
		
		second=(double)mill_sec[0]*3600+mill_sec[1]*60+mill_sec[2]+0.001*mill_sec[3];//时分秒毫秒
		
		//printf("time out :%f\n",second);
		return 0;
		
	}	
};

#endif
