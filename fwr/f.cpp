#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argv, char **argc )
{
	FILE* pLog = fopen("/tmp/atest.log", "ab");
	if(pLog)
	{
		char buf_error[400] = {0};
		sprintf( buf_error, "%s", argc[1] );
		//lseek(pLog,0,SEEK_END);
		fwrite(buf_error, sizeof(char),  strlen(buf_error), pLog  );
		fclose(pLog);
		return 0;
	}
	fclose(pLog);
	return -1;
}
