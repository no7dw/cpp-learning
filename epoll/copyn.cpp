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
#define INFTIM 10000
#define BUFFER_SIZE 512
typedef struct task_t
{
	int fd;
	char buffer[BUFFER_SIZE];
	int n;
}task_t;

void setnonblocking(int sock)
{
	int opts;
	opts = fcntl(sock , F_GETFL);
	if(opts < 0)
	{
		perror("fcntl(sock, GETFL)");
		exit(-1);
	}
	opts = opts|O_NONBLOCK;
	if(fcntl(sock, F_SETFL, opts) < 0)
	{
		perror("fcntl(sock, SETFL, opts)");
		exit(-1);
	}
}
int main()
{
	int i,listenfd, connfd, sockfd, epfd, nfds;
	ssize_t n;
	char line[MAXLINE];
	socklen_t clilen;
	struct epoll_event ev, events[20];
	
	struct sockaddr_in serveraddr;
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	const char *local_addr = "127.0.0.1";
	
	inet_aton(local_addr, &(serveraddr.sin_addr));
	serveraddr.sin_port = htons(SERV_PORT);

	int nOptVal = 1;
	socklen_t nOptLen = sizeof(int);
	if(-1== setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &nOptVal, nOptLen))
	{
		return -1;
	}
	setnonblocking(listenfd);
	bind(listenfd, (sockaddr *)&serveraddr, sizeof(serveraddr) );
	listen(listenfd, LISTENQ);

	epfd = epoll_create(256);
	ev.data.fd = listenfd;
	ev.events = EPOLLIN|EPOLLET;
	epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

	task_t task;
	task_t *ptask;
	while(1)
	{
		nfds = epoll_wait(epfd , events, 20, 500);
		for(i = 0; i < nfds; i++)
		{
			if(events[i].data.fd == listenfd )
			{
				connfd = accept(listenfd, NULL, NULL);
				if(connfd < 0)
				{
					printf("connfd < 0 ,listenfd = %d\n", listenfd);
					printf("error = %s\n", strerror(errno));
					return -1;
				}
				setnonblocking(connfd);
				memset(&task, 0, sizeof(task));
				task.fd = connfd;
				ev.data.ptr = &task;
				ev.events = EPOLLIN|EPOLLET;

				epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);

			}//if
			else if(events[i].events & EPOLLIN)
			{
				cout << "EPOLLIN" << endl;
				ptask = (task_t *)events[i].data.ptr;
				sockfd = ptask->fd;
				if( (ptask->n = read(sockfd, ptask->buffer, BUFFER_SIZE)) < 0)
				{
					if(errno == ECONNRESET)
					{
						close(sockfd);
						events[i].data.ptr = NULL;							
					}
					else
						cout << "read error" << endl;
				}
				else if(ptask->n == 0)
				{
					close(sockfd);
					events[i].data.ptr = NULL;					
				}

				ptask->buffer[ptask->n] = '\0';
				cout << "read " <<  ptask->buffer << endl;

				ev.data.ptr = ptask;
				ev.events = EPOLLOUT|EPOLLET;
				epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
			}
			else if(events[i].events & EPOLLOUT)
			{
				cout << "EPOLLOUT" << endl;
				ptask = (task_t *)events[i].data.ptr;
				sockfd = ptask->fd;
				write(sockfd, ptask->buffer, ptask->n);
				cout << "write " << ptask->buffer<< endl;
				
				ev.data.ptr = ptask;
				epoll_ctl(epfd, EPOLL_CTL_DEL, sockfd, &ev);
				memset(ptask, 0, sizeof(task));
				close(sockfd);

			}
			else 
			{
				cout << "other kind of events" << endl;
			}
		}//for
	}//while
	return 0;
}


























