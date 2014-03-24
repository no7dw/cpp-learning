#include "status.h"
#include <stdio.h>
int status::istatic= 0 ;
status status::theAP;

void status::mod()
{
	istatic ++;
}
void status::output()
{
	printf("istatic = %d\n", istatic);
}
