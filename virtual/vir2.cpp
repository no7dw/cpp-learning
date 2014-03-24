#include "vir2.h"

#include <stdio.h>
void vir2::DrawBackGround()
{
	printf("vir2::  DrawBackGround  \n");
}
void vir2::DrawScore( int index, const char *text_head )
{

	printf("vir2::  DrawScore %d %s \n", index, text_head);
}
void vir2::DrawScore( int index )
{
	printf("vir2::  DrawScore %d  \n", index);
}

