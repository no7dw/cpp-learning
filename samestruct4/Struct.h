#ifndef _STRUCT_H
#define _STRUCT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const short ID_SIZE = 48+1; 
const short  NAME_SIZE = 256;

class sImpl;

struct CourseInfo{
	
	char ID[ID_SIZE];
	char Name[NAME_SIZE];	
	int SendbySM;
	CourseInfo()
	{
	    memset(ID,0,sizeof(ID));
	    memset(Name,0,sizeof(Name));	  
	    SendbySM = 0;
	   
	}
};

#endif