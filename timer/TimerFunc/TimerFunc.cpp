#include "TimerFunc.h"

My_Timer TimerFunc::my_timer[MAX_TIMER_COUNT]={0};
int TimerFunc::m_TimersCount=0;
int TimerFunc::ticker=0;
	
void TimerFunc::SetTimer(int ttime,int ifunction) //新建一个计时器
{   
    struct My_Timer a;
    a.total_time = ttime;
    a.left_time = ttime;
    a.func = ifunction;
    printf("\n index : %d ,total_timer : %d \n" ,m_TimersCount, a.total_time );
    my_timer[m_TimersCount++] = a;
    
}

void TimerFunc::Timeout(int sigty)  //判断定时器是否超时，以及超时时所要执行的动作
{  
    //printf("Signal: %d , Time ticker : %d\n", sigty, ticker++);
    printf(" ticker : %d ",  ticker++);
    
    int j;
    for( j = 0; j < m_TimersCount; j++ )
    {  
        if(my_timer[j].left_time != 0 )
	{
            my_timer[j].left_time--;//continue the counter
	}
        else
        {   
            switch(my_timer[j].func) //通过匹配my_timer[j].func，判断下一步选择哪种操作
	    {
		
		case 1:
		{
			
			printf("doing\n");
						
		}

	    }
	   // my_timer[j].left_time = my_timer[j].total_time;     //循环计时
	    my_timer[j].left_time = 10;     //循环计时
	    printf("\nmy_timer[%d].func : %d\n" ,j ,  my_timer[j].func );
	    printf("\ntotal_timer %d: %d\n" ,j ,  my_timer[j].total_time );
	    printf("Reset Timer to %d \n",my_timer[j].total_time);
	}
    }
}

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
	SetTimer(10,1);
    //     setTimer(4,2);
    //    setTimer(5,3);
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

