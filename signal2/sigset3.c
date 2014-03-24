#include <stdlib.h>
   #include <stdio.h>
   #include <signal.h>
   #include <unistd.h>
   #include <sys/types.h>
   
   
   void my_func()
   {
          printf("If you  want to quit ,pls try  SIGQUIT\n");
  }
  
  int main()
  {
          sigset_t set,pendset;
          struct sigaction action1,action2;
  
          //initialize the set empty
          if(sigemptyset(&set)<0)
          {
                  perror("sigemptyset\n");
                  exit(1);
          }
  
          if(sigaddset(&set,SIGQUIT)<0)
          {
                  perror("sigaddset\n");
                  exit(1);
          }
          if(sigaddset(&set,SIGINT)<0)
          {
                  perror("sigaddset\n");
                  exit(1);
          }
  
          if(sigismember(&set,SIGINT))
          {
                  sigemptyset(&action1.sa_mask);
                  action1.sa_handler=my_func;
                  action1.sa_flags=0;
                  sigaction(SIGINT,&action1,NULL);
  
          }
          if(sigismember(&set,SIGQUIT))
          {       
                  sigemptyset(&action2.sa_mask);
                  action2.sa_handler=SIG_DFL;
                  action2.sa_flags=0;
                  sigaction(SIGQUIT,&action2,NULL);
  
          }
   
          if(sigprocmask(SIG_BLOCK,&set,NULL)<0)
          {
                  perror("sigprocmask");
                  exit(1);
          }
          else
          {       
                  printf("Signal set was blocked,Press any key!\n");
                  getchar();
          }
  
          if(sigprocmask(SIG_UNBLOCK,&set,NULL)<0)
          {
                  perror("sigprocmask");
                  exit(1);
          }
          else
          {
                  printf("Signal set is in unblock state.\n");
          }
          
          while(1);
          
          exit(0);
  
  
  }

