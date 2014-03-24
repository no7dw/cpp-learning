#include "StudyRecordXml.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc , char** argv)
{
	if(argc<2)
	{
		cout<< "Usage: Version filename" << endl;
		return 0;
	}
	
	StudyRecordXml *pStudyRecordXmlObj= new StudyRecordXml();
	pStudyRecordXmlObj->LoadXml(argv[1]);
	
	//method 1
/*	cout<< pStudyRecordXmlObj->GetStudyRecordInfo("000124")->CourseID << endl;
	cout<< pStudyRecordXmlObj->GetStudyRecordInfo("000124")->Study_Interval << endl;
	cout<< pStudyRecordXmlObj->GetStudyRecordInfo("000124")->Study_Score << endl;
	cout<< pStudyRecordXmlObj->GetStudyRecordInfo("000124")->Study_Time << endl;		
	cout<< pStudyRecordXmlObj->GetStudyRecordInfo("000124")->Study_PersonCount << endl;
	cout<< pStudyRecordXmlObj->GetStudyRecordInfo("000124")->PersonA_Score << endl;
	cout<< pStudyRecordXmlObj->GetStudyRecordInfo("000124")->PersonB_Score << endl;*/
	
	//method 2
	cout << endl;
	StudyRecordInfo *pSRI;
	pSRI = pStudyRecordXmlObj->GetStudyRecordInfo("1000000128");
	if (pSRI!=NULL)
	{
	  cout<< pSRI->CourseID  << "\t" << pSRI->CourseName  << "\t"  << pSRI->Study_Interval  << "\t"<< pSRI->Study_Time  << "\t"<< "\t"  ;
	  
	  cout<< pSRI->Flower  << "\t" << pSRI->FirstGrade  << "\t" << pSRI->Study_Score  << "\t" << pSRI->RCount  << "\t" << pSRI->WCount  << "\t"  << "\t"  ;
	  
	  cout<< " Study_PersonCount: " << pSRI->Study_PersonCount  << "\t"  << "\t";
	  	  
	   cout<< pSRI->PersonA_Score  << "\t"<< pSRI->UnAnswerCountA << "\t"  << pSRI->RCountA  << "\t"<< pSRI->WCountA  << "\t"  << "\t" ;	  	  
	 
	  cout<< pSRI->PersonB_Score  << "\t"<< pSRI->UnAnswerCountB << "\t"  << pSRI->RCountB  << "\t" << pSRI->WCountB << endl;		  	  
	  
	}
	else
	  cout << "null" << endl;
	
	
	
	//pSRI = NULL;
	  
	  
	cout << "the following calling vector" << endl;
	
	vector <StudyRecordInfo> VSRI,*pVSRI;
	vector <StudyRecordInfo>::iterator iter;	
	VSRI = *(pStudyRecordXmlObj->GetStudyRecordInfo());
	/*
	pVSRI=pStudyRecordXmlObj->GetStudyRecordInfo();
	if(pVSRI!=NULL)
	{
		VSRI = *(pStudyRecordXmlObj->GetStudyRecordInfo());	
		cout << "pVSRI!=NULL"<<endl;
	}
	else
	{
		cout << "pVSRI==NULL"<<endl;
	}
	*/
	int i =0;
	for( iter = VSRI.begin(); iter != VSRI.end(); ++i , ++iter)
	{
		//cout << i<<" " ;
		//cout << (*iter).CourseID << "\t" << (*iter).Study_Interval << "\t"<< (*iter).Study_Score << "\t"<< (*iter).Study_Time << "\t"<< (*iter).Study_PersonCount << "\t"<< (*iter).PersonA_Score << "\t"<< (*iter).RCountA << "\t" << (*iter).PersonB_Score << "\t"<< (*iter).RCountB << "\t" << endl;
		cout<< "\n CourseID: "<< (*iter).CourseID  << "\t"  << (*iter).CourseName  << "\t" << (*iter).Study_Interval  << "\t"<< (*iter).Study_Time  << "\t"<< "\t"  ;
	  
		cout<< "\n Flower: "<< (*iter).Flower  << "\t" << (*iter).FirstGrade  << "\t" << (*iter).Study_Score << "\t" << (*iter).UnAnswerCount  << "\t" << (*iter).RCount  << "\t" <<  " WCount "<< (*iter).WCount  << "\t"  << "\t"  ;
		
		cout<<  "\n Study_PersonCount " << (*iter).Study_PersonCount  << "\t"  << "\t";
			
		cout<< "\n PersonA_Score: "<< (*iter).PersonA_Score  << "\t" << (*iter).UnAnswerCountA << "\t"  << (*iter).RCountA  << "\t"<< (*iter).WCountA  << "\t"  << "\t" ;	  	  
		
		cout<< "\n PersonB_Score: "<< (*iter).PersonB_Score  << "\t" << (*iter).UnAnswerCountB << "\t" << (*iter).RCountB  << "\t" << (*iter).WCountB << endl;
		
	}
	VSRI.clear();

	
	StudyRecordInfo newSR;
	//memcpy(&newSR, pSRI,sizeof(StudyRecordInfo));
	newSR.CourseID = "19";
	newSR.CourseName = "01 日常";
	newSR.FirstGrade=2;
	newSR.Flower=1;
	newSR.PersonA_Score=6.1;
	newSR.PersonB_Score=4.2;
	newSR.RCount=7;
	newSR.RCountA=6;
	newSR.RCountB=5;
	newSR.Study_Interval=345;
	newSR.Study_PersonCount=3;	
	newSR.Study_Score=6.5;
	newSR.Study_Time="201108091000";
	newSR.UnAnswerCount=1;
	newSR.UnAnswerCountA=2;
	newSR.UnAnswerCountB=3;
	newSR.WCount=4;
	newSR.WCountA=5;
	newSR.WCountB=6;
	
	
	cout << endl << "additem : " << pStudyRecordXmlObj->AddItem(newSR) << endl;
	  
	delete pStudyRecordXmlObj;
	pStudyRecordXmlObj = NULL;		
	
	//method 3
// 	cout << endl;
// 	StudyRecordInfo SRI,*pSRI2;
// 	pSRI2 = pStudyRecordXmlObj->GetStudyRecordInfo("000124");
// 	memcpy( &SRI , pSRI2 , sizeof(StudyRecordInfo) );
// 	cout<< SRI.Study_Score << endl;
	
	return 1;
	
}
