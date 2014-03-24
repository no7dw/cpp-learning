#include "vir.h"
#include <stdio.h>
void vir::DrawScore(int index , const char * text_head)
{
	printf(" vir:: DrawScore %d %s\n", index, text_head);
}
void vir::DrawScore(int index)
{
	printf(" vir:: DrawScore %d \n", index);
}
