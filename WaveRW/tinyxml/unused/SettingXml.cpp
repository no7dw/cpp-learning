#include "SettingXml.h"
#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace std;

SettingXml::SettingXml()
{
	
}
SettingXml::~SettingXml()
{
}

int SettingXml::LoadXml(const char *XmlFilePath)
{

	TiXmlDocument *myDocument = new TiXmlDocument(XmlFilePath);
	myDocument ->LoadFile();
		
	//begin read
	TiXmlElement *RootElement = myDocument->RootElement();//Settings

	TiXmlElement *MacItem = RootElement->FirstChildElement();
	MacAddress =	MacItem->FirstChild()->Value();
	cout << " Mac = "<< MacAddress << endl;
	
	TiXmlElement *AVCoursesScoreSettingItem = MacItem->NextSiblingElement();

	TiXmlElement *FirstPartItem = AVCoursesScoreSettingItem->FirstChildElement();

	int index = 0;
	AVTrainningPartSetting AVTPS;
	
	while ( FirstPartItem != NULL )
	{
		AVTPS.ID = FirstPartItem->Attribute("id");
		
		TiXmlElement *FirstPartLevel_UpgradeValItem = FirstPartItem->FirstChildElement();
		AVTPS.Level_UpgradeVal = atoi(FirstPartLevel_UpgradeValItem->FirstChild()->Value());
		
		TiXmlElement *FirstPartPassScoreItem = FirstPartLevel_UpgradeValItem->NextSiblingElement();
		AVTPS.PassScore = atoi(FirstPartPassScoreItem->FirstChild()->Value());

		TiXmlElement *FirstExcellentScoreItem = FirstPartPassScoreItem->NextSiblingElement();
		AVTPS.ExcellentScore = atoi(FirstExcellentScoreItem->FirstChild()->Value());

		if( FirstPartItem->FirstChild() != NULL )
		{
//		  	CourseListVersions[index] =  FirstPartLevel_UpgradeValItem->FirstChild()->Value() ;
			cout << AVTPS.Level_UpgradeVal  << endl; 
		}

		index = index + 1;
		
		VAVTrainningPartSetting.push_back(AVTPS);
		 
		FirstPartItem = FirstPartItem->NextSiblingElement();
	}
// 	s
	//LastStartPoint Should be compute here 
	
	delete myDocument;//2011-5-13 bug
 
	//end read
	
	cout <<"\nindex = "<< index << "#### Loop done ####" <<endl;
	
	return 1;
}

AVTrainningPartSetting* SettingXml::GetAVCourseSetting(string part)//<T>
{
  vector<AVTrainningPartSetting>::iterator iter;
    int i = 0;
    for( iter = VAVTrainningPartSetting.begin(); iter != VAVTrainningPartSetting.end(); ++i , ++iter)
    {
	//int iFound = part.find(iter->ID);
	//if (iFound != string::npos )
	if(iter->ID == part)
	  return &VAVTrainningPartSetting[i];
	
    }
    return NULL;
}