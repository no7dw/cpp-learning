#include <stdio.h>
#include <stdlib.h>
int   main()
{
struct   stat   buf;
if((stat(   "cplusplus ",&buf))   !=   0)
{
cerr << "wrong! " <<endl;
}

cout <<buf.st_size <<endl;
return   0;
} 
