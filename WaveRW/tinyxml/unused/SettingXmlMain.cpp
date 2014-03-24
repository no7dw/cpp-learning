#include "SettingXml.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc , char** argv)
{
	if(argc<2)
		cout<< "Usage: Version filename" << endl;

	SettingXml *SettingXmlObj= new SettingXml();
	SettingXmlObj->LoadXml(argv[1]);
//	cout<< SettingObj->GetSystemSettingVersion() <<endl;
//	cout<< SettingObj->GetCourseListVersion(4) <<endl;
	
	
	
	AVTrainningPartSetting *pAVTPS;
	pAVTPS = SettingXmlObj->GetAVCourseSetting("2");
	if (pAVTPS!=NULL)
	{
	  cout<< pAVTPS->ID << endl;
	  cout<< pAVTPS->Level_UpgradeVal << endl;
	  cout<< pAVTPS->PassScore << endl;
	  cout<< pAVTPS->ExcellentScore << endl;

	}
	else
	  cout << "null" << endl;
	
	return 1;
}
