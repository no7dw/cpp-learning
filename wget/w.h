#ifndef __TASK_CONTROL_H
#define __TASK_CONTROL_H




extern char BNBT_SERVER_IP[16];
extern char BNBT_SERVER_PORT[5];

#define Max_Jobs 20

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#define TORRENT_SAVE_PATH "/tmp/a.torrent"
class TaskControl
{
public:
	TaskControl();
	~TaskControl();
	
public:
	static void* increment_count(void *arg);
	///@Summary: 添加任务
	static int Task_Add(const char *TorrentHash);
private:

	static pthread_mutex_t count_lock ;
	static pthread_cond_t count_cond;
	static unsigned int count;

};
#endif
