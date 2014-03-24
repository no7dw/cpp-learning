#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
   
   void  my_func(int sign_no)
   {       
           if(sign_no==SIGINT)
           {
                   printf("I have get SIGINT\n");
          }
          else if(sign_no==SIGQUIT)
          {
                  printf("I have get SIGQUIT\n");
          }
  
  
  }
  
  int main()
  {       
	struct sigaction action;
          printf("Waiting for signal SIGINT or SIGQUIT... \n");
          
	action.sa_handler=my_func;
	sigemptyset(&action.sa_mask);
//	action.sa_flags=0;
//	action.sa_flags=SA_NODEFER;
	action.sa_flags=SA_RESTART;
	printf("SA_NODEFER = %d\n",SA_NODEFER);

	printf("SA_RESTART = %d\n",SA_RESTART);

	sigaction(SIGINT,&action,0);
	sigaction(SIGQUIT,&action,0);
          pause();
   
         printf("This is the end\n");
          exit(0);
 }

