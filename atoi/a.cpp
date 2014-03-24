#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(void)
{
	string  str1="1% ";
	string str2="0%";
	string str3="100%";
	printf("atoi(%s), = %d\n",str1.c_str()  , atoi(str1.c_str()));
	printf("atoi(%s), = %d\n",str2.c_str()  , atoi(str2.c_str()));
	printf("atoi(%s), = %d\n",str3.c_str()  , atoi(str3.c_str()));

	string Percent;
	int Last_Percent =20;
	char c_percent[4] = {0};
	sprintf(c_percent, "%d", Last_Percent );
	Percent.assign( c_percent , strlen(c_percent) );
	Percent.append("%");
	printf("\n ************** Percent = %s < Last_Percent = %d %% \
	********************\n", Percent.c_str() , Last_Percent);
}
