#include "utf8_conv.h"
#include <stdio.h>
int main(void)
{
	char src[]="04 鏁板瓧1鍒";
	char dest[255]={0};
	int dest_len =255;
     int iresult = utf8_convert(src,  dest,  dest_len);
     printf("src : %s\n", src);
     printf("dest: %s\n", dest);
     return iresult;
}
