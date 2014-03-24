#include "TimerFunc.h"

#define DEBUG_OUTPUT true

My_Timer TimerFunc::my_timer[MAX_TIMER_COUNT]={0};
int TimerFunc::m_TimersCount=0;
int TimerFunc::ticker=0;

extern int iStatusCounter ;

void TimerFunc::SetTimer(int iInterval,int ifunction) //新建一个计时器
{   
    struct My_Timer a;
    a.total_time = iInterval;
    a.left_time = iInterval;
    a.func = ifunction;
    //printf("\n index : %d ,total_timer : %d \n" ,m_TimersCount, a.total_time );
    my_timer[m_TimersCount++] = a;
    
    
}

void TimerFunc::Timeout(int sigty)  //判断定时器是否超时，以及超时时所要执行的动作
{  
    //printf("Signal: %d , Time ticker : %d\n", sigty, ticker++);
    //printf(" ticker : %d ",  ticker++);
    
	int j;
	//for( j = 0; j <= m_TimersCount; j++ )
	for( j = 0; j <= m_TimersCount; j++ )
	{  
		if(my_timer[j].left_time > 0 )
		{
			my_timer[j].left_time--;//continue the counter
			//printf("Timer %d: left_time = %d \n", j, my_timer[j].left_time);
		}
		else
		{   
			//printf("my_timer[%d].func = %d",j,my_timer[j].func);
			switch(my_timer[j].func) //通过匹配my_timer[j].func，判断下一步选择哪种操作
			{				
				case 1://任务状态的扫描
				{
					printf("fun1\n");									
				}
				break;
				case 2://下载情况检查
				{
					printf("fun2\n");
				}
				break;
			}
			if(my_timer[j].total_time != 0)
			{
				my_timer[j].total_time = my_timer[j].total_time ;
				my_timer[j].left_time = my_timer[j].total_time;     //循环计时	
						
				printf("Reset Timer %d  to %d \n", j , my_timer[j].total_time);
			}
			//printf("\n @@@@@@\t iStatusCounter : %d \n",iStatusCounter);
		}
	}
}

/* 0 定义: 长时间低速: 平均 速度 < 10KB/s ( 1小时内下不足 35MB )
 * 1 定时器（1小时）先保存此前的 vector<>结构类型 的状态信息
 * 2 然后到时间后再获取一遍数据
 * ==================================
 * 3 率选，条件： 状态是：正在下载的任务，并且进度：【0% ～ 100%】
 * 4 刷选后的任务 前后的已下载的数值相减，数值 < 35 MB (35*1024 KB)
 * 5 调用 Event_LowSpeed (记录到UploadData.xml中 )
 */

//int main()  //测试函数，定义三个定时器
int TimerFunc::StartTimer()
{   
    m_TimersCount = 0;
    
    if(ticker>0 )
    {
	return 0;
	printf("already StartTimer\n");
    }
    else
    {
	ticker = 0;
	printf("start StartTimer\n");
    }
    
    pid_t pid;
    if((pid = fork()) < 0)
    {
	return -1;
    }
    else if(pid == 0) //child
    {
	SetTimer(5,1);//计时器1：25秒进行一次任务状态的扫描
	SetTimer(10,2);//计时器2： 半小时进行一次下载情况检查
	
    
	signal(SIGALRM,Timeout);  //接到SIGALRM信号，则执行timeout函数
	while(1)
	{  
	    sleep(1);  //每隔一秒发送一个SIGALRM
	    kill(getpid(),SIGALRM);//the  same  as raise(SIGALRM)
	}
    
    }
    else
	return 0;
    
    
}
