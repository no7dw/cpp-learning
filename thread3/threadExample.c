#include <stdio.h>
#include <pthread.h>

void thread(void *address)
{
	int i;
//	for(i = 0;i < 3;i++)
//	{
		char cmd[200];
		sprintf(cmd,"wget %s\n",(char*) address);
//	}
	printf("cmd = %s", cmd );
	system(cmd);
}

int main(void)
{
	pthread_t id[3];
	int i,ret;
	ret = pthread_create(&id[0],NULL,(void*)thread,(void*)("http://www.wallpapergate.com/data/media/2892/Chinese_Beauty.jpg"));
	ret = pthread_create(&id[1],NULL,(void*)thread,(void*)("http://www.soundoflife.net/wp-content/uploads/2007/10/beauty.jpg"));
	ret = pthread_create(&id[2],NULL,(void*)thread,(void*)("http://hiphotos.baidu.com/baidu/pic/item/8127c7bfdc87295419d81f80.jpg"));
	if(ret!=0)
	{
		printf("Create pthread error!\n");
		exit(1);
	}
	for(i=0;i<3;i++)
	{
		printf("This is the main process.\n");
	}
	pthread_join(id[0],NULL);
	pthread_join(id[1],NULL);
	pthread_join(id[2],NULL);
	return 0;
}

