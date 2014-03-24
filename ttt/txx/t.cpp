#include <stdio.h>
#include <string.h>
int main(void)
{
	int id; 
	char errorMark;
	char doneStr[5]; memset(doneStr, 0, sizeof(doneStr));
	char haveStr[12];memset(haveStr, 0, sizeof(haveStr));
	char haveUnit[3];memset(haveUnit, 0, sizeof(haveUnit)); 
	char etaStr[9];memset(etaStr, 0, sizeof(etaStr));
	double up_tr_speed_K;
	char cspace[10];memset(cspace, 0, sizeof(cspace));
	const char *str = "   1   100%   28.40 MB  Done         1.1";
	sscanf(str, "%4d%c  %4s  %9s %2s  %8s  %6.1f", &id, &errorMark,  doneStr,  haveStr, haveUnit, etaStr, up_tr_speed_K);
	printf("%s\n",str);
	printf("%4d%c  %4s  %9s %2s %-8s  %6.1f\n", id, errorMark, doneStr,haveStr,haveUnit, etaStr, up_tr_speed_K
	);
}
