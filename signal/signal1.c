#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* sigmgr_thread();

int main()
{
    sigset_t bset;
    int             i;
    pid_t           pid = getpid();
    pthread_t       ppid;
   

    // Block SIGTERM and SIGUSR1
    sigemptyset(&bset);
    sigaddset(&bset, SIGTERM);
    sigaddset(&bset, SIGUSR1);
    pthread_sigmask(SIG_BLOCK, &bset, NULL);

   
    pthread_create(&ppid, NULL, sig_thread, NULL);
 
    for (i = 0; i < 50; i++) {
        printf("in main() sleep\n");
        sleep(10);
    }
    exit (0);
}

 
void* sig_thread()
{
    sigset_t   waitset, oset;
    siginfo_t  info;
    int        rc;

    sigemptyset(&waitset);
    sigaddset(&waitset, SIGTERM);
    sigaddset(&waitset, SIGUSR1);

    while (1)  {
        printf("in sig_thread()\n");
        rc = sigwaitinfo(&waitset, &info);
        if (rc != -1) {
            printf("sigwaitinfo() get a signal - %d\n", rc);
            if (info.si_signo == SIGUSR1)
                                printf("sigwaitinfo() get a signal - %d\n", rc);
            else if (info.si_signo == SIGRTMIN)
                                printf("sigwaitinfo() get a signal - %d\n", rc);
           
        } else {
            printf("sigwaitinfo() returned err: %d; %s\n", errno, strerror(errno));
        }
    }
}
