#include "PartsInfoXml.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc , char** argv)
{
	if(argc<2)
		cout<< "Usage: Version filename" << endl;

	PartsInfoXml *PartsInfoXmlObj= new PartsInfoXml();
	PartsInfoXmlObj->LoadXml(argv[1]);

//	cout<< SettingObj->GetSystemSettingVersion() <<endl;
//	cout<< SettingObj->GetCourseListVersion(4) <<endl;
	
	PartInfo *pPI,PI;
	char cpart[3]={0};
	for(int index =1;index <=12;index++ )
	{
		sprintf(cpart,"%d", index);
		pPI = PartsInfoXmlObj->GetPartInfo(cpart);
		if (pPI!=NULL)
		{
		  cout<< pPI->PartID << endl;
		  cout<< pPI->PartName << endl;
		  cout<< pPI->Flowers << endl;
		  cout<< pPI->CourseCount << endl;
		  cout<< pPI->CouseLearned << endl;
		  cout<< pPI->Grade_UpdateTime << endl;
		  cout<< pPI->Study_Time << endl;
		  cout<< pPI->Study_Times << endl;
		   

		}
		else
		  cout << "null" << endl;
	}
	return 0;
		
	PI= *pPI;
	if (pPI!=NULL)
	{
	  cout<< PI.PartID << endl;
	  cout<< PI.PartName << endl;
	  cout<< PI.Flowers << endl;
	  cout<< PI.CourseCount << endl;
	  cout<< PI.CouseLearned << endl;
	  cout<< PI.Grade_UpdateTime << endl;
	  cout<< PI.Study_Time << endl;
	  cout<< PI.Study_Times << endl;
	   

	}
	
	
	PI.Flowers = 1 ;
	PI.CourseCount = 1 ;
	PI.CouseLearned = 1 ;
	PI.Grade_UpdateTime = "00:00:08" ;
	PI.Study_Time = "201112212324" ;
	PI.Study_Times = 1 ;
	  
	PartsInfoXmlObj->UpdatePartInfo("2",PI);
	
	delete PartsInfoXmlObj;
	PartsInfoXmlObj = NULL;
	return 1;
	
}
