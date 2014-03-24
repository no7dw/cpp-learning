#include <include/linux/timer.h>
//#include <linux/timer.h>
#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

struct list_head {
struct list_head *next, *prev;
};

struct timer_list {
struct list_head list;
unsigned long expires;
unsigned long data;
void (*function)(unsigned long);
};

//将定时器加到定时器队列中
//void add_timer(struct timer_list *timer);

//修改定时器的到期时间
//int mod_timer(struct timer_list *timer, unsigned long expires);


//将定时器删除(以后这个定时器将不再起作用)
//int del_timer(struct timer_list * timer);

void todo()
{
	printf("what happened ? \n");
}

int main()
{

	struct timer_list *timer
	timer->expires=10;
	timer->data=20;
	timer->function=(void*)todo;
	add_timer(timer);

}
