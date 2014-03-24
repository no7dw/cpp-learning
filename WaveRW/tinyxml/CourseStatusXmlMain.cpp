#include "CourseStatusXml.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc , char** argv)
{
	if(argc<2)
	{
		cout<< "Usage: Version filename" << endl;
		return -1;
	}

	CourseStatusXml *pCourseStatusObj= new CourseStatusXml();
	pCourseStatusObj->LoadXml(argv[1]);
	
	
	vector<CourseStatus> *pVCMI1;

	int iRetStatus = pCourseStatusObj->GetCourseStatus("20003");	//BUG:: this time we still not have the 20008 because not load the newest xml
	//int iRetStatus2 = pCourseStatusObj->IsCourseNew ("20003");
	
	cout << "id " << iRetStatus << " iRetStatus "<< iRetStatus /* << " iRetStatus2 "<< iRetStatus2 */<< endl; 			
	
	CourseStatus *pCMI,CI1;
	CI1.CourseID = "20009";
	CI1.iStatus = 80;
	
	cout <<" result AddItem: "<< pCourseStatusObj->AddItem(CI1) << endl;
	cout <<" result RemoveItem: "<< pCourseStatusObj->RemoveItem("20002") << endl;
	
	cout <<" result UpdateStatus: "<< pCourseStatusObj->UpdateStatus("20003", 4) << endl;
	
	delete pCourseStatusObj;
	pCourseStatusObj =NULL;
	
	//BUG:: why we have such error  *** glibc detected *** /home/dengwei/RTD1073/work3/MyDLL/tinyxml/CourseStatus: corrupted double-linked list: 0x080584f8 *** 
	//when we delete
	return 0;

	
}
