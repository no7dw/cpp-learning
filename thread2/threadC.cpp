#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
pthread_t pid_new_job;
#define ID_SIZE 48+1 //由于软件升级，该为存取软件升级包的Hash
#define NAME_SIZE 256
#define PATH_SIZE 100+1
#define HASH_SIZE 48+1

struct CourseInfo{
	
	char ID[ID_SIZE];
	char Name[NAME_SIZE];
	char Path[PATH_SIZE];
	char Hash[HASH_SIZE];
	int Level;//1-12阶段
	int Grade;//优先级别
	int SendbySM;//那个模式的
	int Status;//状态 0 UNBOOK 1 BOOK 2 DOWNLOADING 3 COMPLETED
	int Last_Percent;
	CourseInfo()
	{
	    memset(ID,0,sizeof(ID));
	    memset(Name,0,sizeof(Name));
	    memset(Path,0,sizeof(Path));
	    memset(Hash,0,sizeof(Hash));	    
	    Level = 0;
	    Grade = 0;
	    SendbySM = 0;
	    Status = 1;
	    Last_Percent = 0;
	}
};

void *thread_handleSpace(void *args)
{
	printf("\n======= thread_handleSpace Begin =======\n");
	CourseInfo *pCI = (CourseInfo*)args;
	printf(" pCI : %s\t%s\t%s\t%d\t%d \n", pCI->ID, pCI->Hash, pCI->Name, pCI->Grade ,pCI->Status);
	printf("\n======= thread_handleSpace End =======\n");
	pthread_exit(NULL);
}

int main(void)
{
	CourseInfo NextCourseInfo;
	strcpy(NextCourseInfo.ID ,"121");
	strcpy(NextCourseInfo.Hash ,"abcd1245");
	strcpy(NextCourseInfo.Name ,"this is the name");
	pthread_attr_t attr;
		
	int res ;
	res = pthread_attr_init(&attr);
	if(res != 0)
	{
		printf("exit 1");
		return -1;
	}
	
	res = pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	res += pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(res != 0)
	{
		printf("exit 2");
		return -1;
	}
	
	res = pthread_create(&pid_new_job, NULL, thread_handleSpace, (void *) &NextCourseInfo);
	pthread_join(pid_new_job,NULL);
	return 0;
}
