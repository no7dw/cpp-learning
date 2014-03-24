
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
   if(argc<2)
	return -1;

   FILE *fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen(argv[1], "r");
   if (fp == NULL)
       exit(EXIT_FAILURE);

	char ce = ' ';
	
   //while ((read = getline(&line, &len, fp)) != -1) {
   while ((read = getdelim(&line, &len, ce , fp)) != -1) {
       printf("Retrieved line of length %zu :\n", read);
       printf("%s", line);
   }

   free(line);
   exit(EXIT_SUCCESS);
}

