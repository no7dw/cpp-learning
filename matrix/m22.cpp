#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	char **buf = new char*[3]; 
	int i;
	for(i = 0;i<3;i++)
	{
		buf[i] = new char[200];
	}	
	for(i = 0;i<3;i++)
	{
		delete[] buf[i];
		buf[i] = NULL;
	}

	delete[] buf;
	buf = NULL;
  	return 0;
}
