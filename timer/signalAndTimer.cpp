   //start  
 
   #include <signal.h>  
   #include <sys/time.h>  
   #include <stdio.h>  
   #include <stdlib.h>  
   static void sighandler(int sigty);  
   bool goon=true;  
   int tot,last;  
   int main(){  
   struct itimerval v;  
   if (signal(SIGUSR1,sighandler)==SIG_ERR){  
   printf("error on reg");  
   exit(1);  
   }

   if (signal(SIGALRM,sighandler)==SIG_ERR){  
   printf("error on reg");  
   exit(2);  
   }

   v.it_value.tv_sec=0; //定时3秒  
   v.it_value.tv_usec=300000;  
   v.it_interval.tv_sec=0;//只做一次  
   v.it_interval.tv_usec=0;  

   setitimer(ITIMER_REAL,&v,NULL);  
   printf("timer has be seted\n");  
   tot=0;  
   //last=v.it_value.tv_sec;  
   last=v.it_value.tv_usec;  

   goon=true;  

   while (goon){  
   getitimer(ITIMER_REAL,&v);  
   //int now = v.it_value.tv_sec;  
   int now = v.it_value.tv_usec;  
   //printf("now: %d\n",now);  
   if (now==last-1){  
    printf("raise SIGUSR1 ");
	raise(SIGUSR1);  
   tot++;  
   }

   last=now;  
   }

    
   return 0;  
   }

   static void sighandler(int sigty){  
   if (sigty==SIGUSR1){  
   struct itimerval v;  
   getitimer(ITIMER_REAL,&v);  
   printf("real time: %ld sec %ld\n",v.it_value.tv_sec ,v.it_value.tv_usec  );  
   }else if (sigty==SIGALRM){  
   printf("timer stop\n");  
   goon=false;  
   }  
   }  
   //end  
