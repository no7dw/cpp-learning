#include "SettingXml.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc , char** argv)
{
	if(argc<2)
	{
		cout<< "Usage: Setting filename" << endl;
		return -1;
	}

	SettingXml *pSettingXmlObj= new SettingXml();
	pSettingXmlObj->LoadXml(argv[1]);
	
	cout<< pSettingXmlObj->SetUserName("Dengwei2")<<endl;
	cout<< pSettingXmlObj->SetAvatar("111.png")<<endl;

	//pSettingXmlObj->LoadXml(argv[1]);
	cout<< pSettingXmlObj->GetAvatar() << endl;
	cout<< pSettingXmlObj->GetUserName() << endl;
	cout<< pSettingXmlObj->GetCurrentLevel(0) << endl;
	cout<< pSettingXmlObj->GetTestPersonCount(0) << endl;
	cout<< pSettingXmlObj->GetPassLine(0) << endl;
	//cout<< pSettingXmlObj->GetExcellentLine() << endl;
	for(int levelindex = 0;levelindex < 12;levelindex++)
		cout<< pSettingXmlObj->GetLevelLine(0,levelindex) << "\t";
	
	UserInfo *pUserInfo;
	pUserInfo  = pSettingXmlObj->GetUserInfo();
	cout << pUserInfo->EquipSN <<"\t";
	cout << pUserInfo->avatar <<"\t";
	cout << pUserInfo->username <<"\t";
	cout << pUserInfo->NetUserName <<"\t";
	cout << pUserInfo->NetPassWord << endl;
	
	cout <<"SetNetUserName_PassWord result: "<< pSettingXmlObj->SetNetUserName_PassWord("u13560335342","p13560335342") << endl;
	
	cout << "SetCurrentLevel result : " << pSettingXmlObj->SetCurrentLevel(0, 9 ) << endl;
	cout << "SetTestPersonCount result : " << pSettingXmlObj->SetTestPersonCount(1, 3 ) << endl;
	cout << "SetPassLine result : " << pSettingXmlObj->SetPassLine(1, 6.2 ) << endl;
	
	cout << "SetExcellentLine result : " << pSettingXmlObj->SetExcellentLine(0, 8.8 ) << endl;
	
	cout << "SetLevelLine,1,0,32 result : " << pSettingXmlObj->SetLevelLine(1, 0, 32 ) << endl;
	cout << "SetLevelLine,0,9,34 result : " << pSettingXmlObj->SetLevelLine(0, 9, 34 ) << endl;
	
	cout << "GetSpeedMode 1 result : " << pSettingXmlObj->GetSpeedMode(1  ) << endl;
	cout << "SetSpeedMode,1 ,1 result : " << pSettingXmlObj->SetSpeedMode(1, 1 ) << endl;
	
	delete pSettingXmlObj;
	pSettingXmlObj = NULL;
	return 0;
}
