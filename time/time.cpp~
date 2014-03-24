#include <string.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;
string UTIL_GetLocalTimeString()
{
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime ); 
	char year[5];
	char mon[3];
	char day[3];
	char hour[3];
	
	char min[3];
	char sec[3];

	strftime(year,5,"%Y",timeinfo);
	strftime(mon,3,"%m",timeinfo);
	strftime(day,3,"%d",timeinfo);
	strftime(hour,3,"%H",timeinfo);
	strftime(min,3,"%M",timeinfo);
	strftime(sec,3,"%S",timeinfo);
	 
	string timestr;
	timestr.append(year);
	timestr.append(mon);
	timestr.append(day);
	timestr.append(hour);
	timestr.append(min);
	timestr.append(sec);

	return timestr;
}

int main(void)
{
	time_t tNow = time(NULL);
	char *szTime = asctime(localtime(&tNow));
	szTime[strlen(szTime) -1] ='\0';
	printf("\n asctime : %s\n", szTime);

	char pTime[256];
	memset(pTime, 0 , sizeof(char)* 256);
	strftime(pTime, sizeof(char)*256, "%Y-%m-%d %H:%M:%S",localtime(&tNow));
	printf("\nstrftime : %s\n",pTime);

	printf("\n%s\n", UTIL_GetLocalTimeString().c_str());
	return 0;
}
