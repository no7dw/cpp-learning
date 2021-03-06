#include <iostream>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAXLINE 5
#define OPEN_MAX 100
#define LISTENQ 20
#define SERV_PORT 5000
#define INFTIM 1000

typedef struct task_t
{
    int fd;
    char buffer[100];
    int n;
}task_t;

int CreateWorker(int nWorker)
{
    if (0 < nWorker)
    {
        bool bIsChild;
        pid_t nPid;

        while (!bIsChild)
        {
            if (0 < nWorker)
            {
                nPid = ::fork();
                if (nPid > 0)
                {
                    bIsChild = false;
                    --nWorker;
                }
                else if (0 == nPid)
                {
                    bIsChild = true;
                    printf("create worker %d success!\n", ::getpid());
                }
                else
                {
                    printf("fork error: %s\n", ::strerror(errno));
                    return -1;
                }
            }
            else 
            {
                int nStatus;
                if (-1 == ::wait(&nStatus))
                {					
                    ++nWorker;
					printf(" ### \t\twait = -1 , nStatus = %d n, nworker = %d\n",nWorker);
                }
            }
        }
    }

    return 0;
}

void setnonblocking(int sock)
{
    int opts;
    opts=fcntl(sock,F_GETFL);
    if(opts<0)
    {
        perror("fcntl(sock,GETFL)");
        exit(1);
    }
    opts = opts|O_NONBLOCK;
    if(fcntl(sock,F_SETFL,opts)<0)
    {
        perror("fcntl(sock,SETFL,opts)");
        exit(1);
    }   
}

void dosomejob()
{
	usleep(200);
}

int main()
{
    int i, maxi, listenfd, connfd, sockfd,epfd,nfds;
    ssize_t n;
    char line[MAXLINE];
    socklen_t clilen;
    struct epoll_event ev,events[20];

    struct sockaddr_in clientaddr;
    struct sockaddr_in serveraddr;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    const char *local_addr = "127.0.0.1";
    inet_aton(local_addr,&(serveraddr.sin_addr));//htons(SERV_PORT);
    serveraddr.sin_port=htons(SERV_PORT);
      // 地址重用
    int nOptVal = 1;
    socklen_t nOptLen = sizeof(int);
    if (-1 == ::setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &nOptVal, nOptLen))
    {
        return -1;
    }    
    setnonblocking(listenfd);
    bind(listenfd,(sockaddr *)&serveraddr, sizeof(serveraddr));
    listen(listenfd, LISTENQ);    
    
    CreateWorker(5);
    
    //把socket设置为非阻塞方式
    
    //生成用于处理accept的epoll专用的文件描述符
    epfd=epoll_create(256);    
    //设置与要处理的事件相关的文件描述符
    ev.data.fd=listenfd;
    //设置要处理的事件类型
    ev.events=EPOLLIN|EPOLLET;
    //ev.events=EPOLLIN;
    //注册epoll事件
    epoll_ctl(epfd,EPOLL_CTL_ADD,listenfd,&ev);
 
     //CreateWorker(5);
     
    maxi = 0;
    
    task_t task; 
    task_t *ptask;
    while(true) 
    {
		//int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);
		//参数events用来从内核得到事件的集合，maxevents告之内核这个events有多大，这个maxevents的值不能大于创建epoll_create()时的size，参数timeout是超时时间
        //等待epoll事件的发生
        nfds=epoll_wait(epfd,events,20,500);
        //处理所发生的所有事件     
        for(i=0;i<nfds;++i)
        {
            if(events[i].data.fd==listenfd)
            {                
                connfd = accept(listenfd,NULL, NULL);
                if(connfd<0){                    
                    printf("connfd<0, listenfd = %d\n", listenfd);
                    printf("error = %s\n", strerror(errno));
                    exit(1);
                }
                setnonblocking(connfd);
               
                //设置用于读操作的文件描述符
                memset(&task, 0, sizeof(task));
                task.fd = connfd;
                ev.data.ptr = &task;
                //设置用于注册的读操作事件
                ev.events=EPOLLIN|EPOLLET;
                //ev.events=EPOLLIN;
                //注册ev
                epoll_ctl(epfd,EPOLL_CTL_ADD,connfd,&ev);
            }
            //对应的文件描述符可以读（包括对端SOCKET正常关闭）
            else if(events[i].events&EPOLLIN)
            {
                cout << "EPOLLIN" << endl;
                ptask = (task_t*)events[i].data.ptr;
                sockfd = ptask->fd;
                
                if ( (ptask->n = read(sockfd, ptask->buffer, 100)) < 0) {
                    if (errno == ECONNRESET) {
                        close(sockfd);
                        events[i].data.ptr = NULL;
                    } else
                        std::cout<<"readline error"<<std::endl;
                } else if (ptask->n == 0) {
                    close(sockfd);
                    events[i].data.ptr = NULL;
                }
                ptask->buffer[ptask->n] = '\0';
                cout << "read " << ptask->buffer << endl;
                
                //设置用于写操作的文件描述符                                
                ev.data.ptr = ptask;
                //设置用于注测的写操作事件
                ev.events=EPOLLOUT|EPOLLET;
                                
                //修改sockfd上要处理的事件为EPOLLOUT
                epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
            }
            //对应的文件描述符可以写
            else if(events[i].events&EPOLLOUT)
            {   
                cout << "EPOLLOUT" << endl;
                ptask = (task_t*)events[i].data.ptr;
                sockfd = ptask->fd;
                //dosomejob();
                write(sockfd, ptask->buffer, ptask->n);
                
                //设置用于读操作的文件描述符              
                ev.data.ptr = ptask;
                
                //修改sockfd上要处理的事件为EPOLIN
                epoll_ctl(epfd,EPOLL_CTL_DEL,sockfd,&ev);
                cout << "write " << ptask->buffer;
                memset(ptask, 0, sizeof(*ptask));
                close(sockfd);
            }
            else if(events[i].events&EPOLLPRI)
            {
				 cout << "#3 EPOLLPRI" << endl;
			}
			else if(events[i].events&EPOLLERR)
            {
				 cout << "#4 EPOLLERR" << endl;
			}
			else if(events[i].events&EPOLLHUP)
            {
				 cout << "#5 EPOLLHUP" << endl;
			}
			else if(events[i].events&EPOLLET)
            {
				 cout << "#6 EPOLLET：" << endl;
			}
			else if(events[i].events&EPOLLONESHOT)
            {
				 cout << "#7 EPOLLONESHOT" << endl;
			}
        }//for
    }//while
    return 0;
}
/*
events可以是以下几个宏的集合：
EPOLLIN ：表示对应的文件描述符可以读（包括对端SOCKET正常关闭）；
EPOLLOUT：表示对应的文件描述符可以写；
EPOLLPRI：表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）；
EPOLLERR：表示对应的文件描述符发生错误；
EPOLLHUP：表示对应的文件描述符被挂断；
EPOLLET： 将EPOLL设为边缘触发(Edge Triggered)模式，这是相对于水平触发(Level Triggered)来说的。
EPOLLONESHOT：只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里
*/