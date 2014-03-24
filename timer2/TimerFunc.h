#ifndef __TIMER_FUNC_H 
#define __TIMER_FUNC_H


#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<sys/time.h>

#define MAX_TIMER_COUNT 10  //设置最大的定时器个数

struct My_Timer //Timer结构体，用来保存一个定时器的信息
{   
	int total_time;  //每隔total_time秒
	int left_time;   //还剩left_time秒
	int func;        //该定时器超时，要执行的代码的标志
};    //定义Timer类型的数组，用来保存所有的定时器

class TimerFunc
{    
public:

	//start the some sec loop
	static int StartTimer();
private:
    
	//int timer_totaltime; //i代表定时器的个数；t表示时间，逐秒递增
	static My_Timer my_timer[MAX_TIMER_COUNT];
	static int m_TimersCount;
	static int ticker;
private:

	//when some sec end do the THING
	static void Timeout(int sigty);
	
	///@Summary: set the ticker and function
	///@Param :计时器的间隙 
	///@Param :到时间后执行的函数序号。
	static void SetTimer(int iInterval,int ifunction);
	
	//static void LowSpeedCheck(vector<JobInfo_CourseInfo> &m_vJI_CI_before_for_Check_LowSpeed_Old,vector<JobInfo_CourseInfo> &m_vJI_CI_before_for_Check_LowSpeed_New);
};
    
#endif
