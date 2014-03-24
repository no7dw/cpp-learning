#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int ConstructFilePath(int mode , int Level ,const string CourseName, char *FilePath )
{
	switch (mode)
	{
		case 0:
			sprintf(FilePath , "/STXD/第%d阶/%s", 10 , "Fruit");
			break;
		case 1:
			sprintf(FilePath , "/KTXDC/第%d阶/%s", 10 , "Fruit");
			break;
		default:
			break;
	}
}

int main(void)
{
	char filepath[100] = {0};
	ConstructFilePath(0 , 10 , "Fruit", filepath);
	
//	sprintf(filepath , "/STXD/第%d阶/%s", 10 , "Fruit");
	printf("filepath = %s\n", filepath);

}
