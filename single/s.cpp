#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int lockfile(int fd) 
{
        struct flock fl; 

        fl.l_type = F_WRLCK;
        fl.l_start = 0;
        fl.l_whence = SEEK_SET;
        fl.l_len = 0;
        return(fcntl(fd, F_SETLK, &fl));
}



int daemonize(const char *cmd)
{
	int i, fd0, fd1, fd2;
	pid_t pid;
	struct rlimit r1;
	struct sigaction sa;
	
	umask(0);
	
	if(getrlimit(RLIMIT_NOFILE, &r1) <0)
		return -1;
	
	if((pid = fork()) < 0)
		return -1;//can't fork
	else if( pid != 0)
		exit(0);
	
	setsid();
	
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if(sigaction(SIGHUP, &sa, NULL) < 0)
		return -1;//can't ignore SIGHUP
	
	if((pid =fork()) < 0)
		return -1;//can't fork
	else if( pid != 0)
		exit(0);
	
	if(chdir("/") < 0)
		return -1;//can't change dir to /
		
	if(r1.rlim_cur == RLIM_INFINITY)
		r1.rlim_max = 1024;
	
	for(i = 0 ;i <r1.rlim_max; i++)
		close(i);
	
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);
	
	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if(fd0 != 0 ||fd1 != 1 || fd2 != 2)
	{
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d" , fd0, fd1, fd2);
		exit(1);
	}		
}
#define LOCKFILE "/var/run/daemon.pid"
#define LOCKMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

int already_running(void)
{
	int fd;
	char buf[16];
	
	fd = open(LOCKFILE, O_RDWR|O_CREAT, LOCKMODE);
	if(fd < 0)
	{
		syslog(LOG_ERR, "cann't open %s :%s", LOCKFILE, strerror(errno));
		exit(1);
	}
	if(lockfile(fd) < 0)
	{
		if(errno == EACCES || errno == EAGAIN)
		{
			close(fd);
			return (1);
		}
		syslog(LOG_ERR, "cann't lock %s :%s", LOCKFILE, strerror(errno));
		exit(1);		
	}
	ftruncate(fd, 0);
	sprintf(buf, "%ld", (long) getpid());
	write(fd, buf, strlen(buf) +1);
	return (0);
	
}

int main(int argc ,char *argv[])
{
		int err;
		pthread_t tid;
		char *cmd;
		struct sigaction sa;
		if((cmd =strchr(argv[0], '/')) == NULL)
			cmd = argv[0];
		else
			cmd++;
		daemonize(cmd);
		if(already_running())
		{
			syslog(LOG_ERR, "daemon already running");
			exit(1);
		}
		else
		{
			printf("run now sleep\n");
			sleep(100);
			printf("exit now \n");
		}
}