#include <unistd.h>
#include <sys/types.h>
main()
{
	int pipe_fd[2];
	pid_t pid;
	char r_buf[4];
	char** w_buf[256];
	int childexit=0;
	int i;
	int cmd;
	
	memset(r_buf,0,sizeof(r_buf));
	if(pipe(pipe_fd)<0)
	{
		printf("pipe create error\n");
		return -1;
	}
	if((pid=fork())==0)
	//子进程：解析从管道中获取的命令，并作相应的处理
	{
		printf("\n");
		close(pipe_fd[1]);
		sleep(2);
		
		while(!childexit)
		{	
			read(pipe_fd[0],r_buf,4);
			cmd=atoi(r_buf);
			if(cmd==0)
			{
printf("child: receive command from parent over\n now child process exit\n");
				childexit=1;
			}
			
		       else if(handle_cmd(cmd)!=0)
				return;
			sleep(1);
		}
		close(pipe_fd[0]);
		exit(1);
	}
	else if(pid>0)
	//parent: send commands to child
	{
	close(pipe_fd[0]);
	w_buf[0]="003";
	w_buf[1]="005";
	w_buf[2]="777";
	w_buf[3]="000";
	for(i=0;i<4;i++)
		write(pipe_fd[1],w_buf[i],4);
	close(pipe_fd[1]);
	}	
}
//下面是子进程的命令处理函数（特定于应用）：
int handle_cmd(int cmd)
{
if((cmd<0)||(cmd>256))
//suppose child only support 256 commands
	{
	printf("child: invalid command \n");
	return -1;
	}
printf("child: the cmd from parent is %d\n", cmd);
return 0;
}

