
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Lxml.h"
#include "Convert.h"
#include "wave.h"

using namespace std;

int main(int argc, char **argv)
{

	if( argc < 3 )
	{
		cout<< "Usage: L xml_filename src_file " << endl;
		return -1;
	}
	Lxml *pLxmlObj= new Lxml();
	pLxmlObj->LoadXml(argv[1]);
	
	
	int size = pLxmlObj ->GetArraySize();
	double start_sec;
	double end_sec;
	
	vector<LTimeText> *pvLTT = pLxmlObj->GetAllLTimeText();
	vector<LTimeText>::iterator viter;
	int i =0;
	for (viter=pvLTT->begin() ;viter!=pvLTT->end(); viter++,i++)
	{
		double sec; 
		
		
		char ctmpstart[12]={0};
		char ctmpend[12]={0};
		
		 strcpy( ctmpstart , (*viter).StartTime.c_str() );
		 Convert::ToIntMillTime ( ctmpstart , sec );
		 start_sec = (sec );
				 
		 
		  
		  strcpy( ctmpend ,  (*viter).EndTime.c_str());
		  Convert::ToIntMillTime ( ctmpend , sec );
		  
		  end_sec = (sec );
		  char tmpfile[20]={0};

		  sprintf(tmpfile,"/tmp/pcm/%d.pcm",i);
		  
		  printf("%s\t%f\t%f\n",tmpfile,start_sec, end_sec);
		  GenWaveFileInSec(argv[2],tmpfile, start_sec*1000, end_sec*1000);
	}
	
	delete pLxmlObj;
	pLxmlObj = NULL;
	
	return 0;
	
}
