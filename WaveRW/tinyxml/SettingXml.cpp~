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
	if(XXml::LoadXml(XmlFilePath)<0)
		return -1;
	
	myDocument = new TiXmlDocument(XmlFilePath);
	myDocument ->LoadFile();
		
	//begin read
	pRootElement = myDocument->RootElement();//Settings
	if(pRootElement == NULL)
		return -1;
	
	TiXmlElement *EquipSNElem = pRootElement->FirstChildElement();
	uinfo.EquipSN = EquipSNElem->FirstChild()->Value();

	TiXmlElement *AvatarElem = EquipSNElem->NextSiblingElement();
	uinfo.avatar = AvatarElem->FirstChild()->Value();
	
	TiXmlElement *UserNameElem = AvatarElem->NextSiblingElement();
	uinfo.username = UserNameElem->FirstChild()->Value();
	
	TiXmlElement *NetUserNameElem = UserNameElem->NextSiblingElement();
	uinfo.NetUserName = NetUserNameElem->FirstChild()->Value();
	
	TiXmlElement *NetPassWordElem = NetUserNameElem->NextSiblingElement();
	uinfo.NetPassWord = NetPassWordElem->FirstChild()->Value();
	
	
	TiXmlElement *StudyModeElem = NetPassWordElem->NextSiblingElement();
	TiXmlElement *FirstTrainingElem = StudyModeElem->FirstChildElement();//AVTraing	

	int index = 0;
	
	
	while ( FirstTrainingElem != NULL )
	{
		string TrainningName = FirstTrainingElem->Value();
		 TiXmlElement *CurrentLevelElem = FirstTrainingElem->FirstChildElement();
		  avSet[index].CurrentLevel = atoi(CurrentLevelElem->FirstChild()->Value());
		  
		  TiXmlElement *TestPersonCountItem = CurrentLevelElem->NextSiblingElement();
		  avSet[index].TestPersonCount = atoi(TestPersonCountItem->FirstChild()->Value());
		  
		  TiXmlElement *PassLineItem = TestPersonCountItem->NextSiblingElement();
		  avSet[index].PassLine = atof(PassLineItem->FirstChild()->Value());
		  
		  TiXmlElement *ExclellentLineItem = PassLineItem->NextSiblingElement();
		  avSet[index].ExcellentLine = atoi(ExclellentLineItem->FirstChild()->Value());
		  
		if(TrainningName == "AVT" )
		{
			TiXmlElement *LevelLineXItem = ExclellentLineItem->NextSiblingElement();
			for(int levelindex = 0 ; levelindex < 12 && LevelLineXItem != NULL ; levelindex++ )
			{			
				avSet[index].LevelLine[levelindex] = atoi(LevelLineXItem->FirstChild()->Value());
				LevelLineXItem = LevelLineXItem->NextSiblingElement();
			}
		}
		else if(TrainningName == "VPT" && index == 1)
		{
			TiXmlElement *SpeedModeItem = ExclellentLineItem->NextSiblingElement();
			avSet[index].SpeedMode = atoi(SpeedModeItem->FirstChild()->Value());
		}
		else if(TrainningName == "LST"&& index == 2)
		{
			TiXmlElement *LevelLineItem = ExclellentLineItem->NextSiblingElement();
			avSet[index].LevelLine[0] = atoi(LevelLineItem->FirstChild()->Value());
		}
		else
		{
		}		
		  
		index = index + 1;		 
		 
		FirstTrainingElem = FirstTrainingElem->NextSiblingElement();
	}

	
	cout <<"\nindex = "<< index << "#### Loop done ####" <<endl;
	
	return 1;
}

////////////////System Setting////////////////
string SettingXml::GetAvatar()
{
  return uinfo.avatar;
}
string SettingXml::GetUserName()
{
  return uinfo.username;
}
int SettingXml::SetAvatar(string AvastarPath)	
{
	if(pRootElement != NULL)
	{
		TiXmlElement *EquipSNElem = pRootElement->FirstChildElement();
		TiXmlElement *AvatarElem = EquipSNElem->NextSiblingElement();
		AvatarElem->FirstChild()->SetValue(AvastarPath.c_str());
		myDocument->SaveFile();
		return 0;
	}
	return -1;
}

int SettingXml::SetUserName(string UserName)	
{
	if(pRootElement != NULL)
	{
		TiXmlElement *EquipSNElem = pRootElement->FirstChildElement();
		TiXmlElement *AvatarElem = EquipSNElem->NextSiblingElement();
		TiXmlElement *UserNameElem = AvatarElem->NextSiblingElement();
		UserNameElem->FirstChild()->SetValue(UserName.c_str());

		myDocument->SaveFile();
		return 0;
	}
	return -1;
}

UserInfo* SettingXml::GetUserInfo()
{
	return &uinfo;
}

int SettingXml::SetNetUserName_PassWord(string netUserName, string netPassWord)
{
	if(pRootElement != NULL)
	{
		TiXmlElement *EquipSNElem = pRootElement->FirstChildElement();
		TiXmlElement *AvatarElem = EquipSNElem->NextSiblingElement();
		TiXmlElement *UserNameElem = AvatarElem->NextSiblingElement();
		TiXmlElement *NetUserNameElem = UserNameElem->NextSiblingElement();
		NetUserNameElem->FirstChild()->SetValue(netUserName.c_str());
		TiXmlElement *NetPassWordElem = NetUserNameElem->NextSiblingElement();
		NetPassWordElem->FirstChild()->SetValue(netPassWord.c_str());

		myDocument->SaveFile();
		return 0;
	}
	return -1;
}

TiXmlElement* SettingXml::GetElem(int Smode , string NodeElemName , int LevelIndex )
{
	if(pRootElement != NULL)
	{
		TiXmlElement *EquipSNElem = pRootElement->FirstChildElement();
		TiXmlElement *AvatarElem = EquipSNElem->NextSiblingElement();
		TiXmlElement *UserNameElem = AvatarElem->NextSiblingElement();
		TiXmlElement *NetUserNameElem = UserNameElem->NextSiblingElement();		
		TiXmlElement *NetPassWordElem = NetUserNameElem->NextSiblingElement();
		
		TiXmlElement *StudyModeElem = NetPassWordElem->NextSiblingElement();		
		TiXmlElement *FirstTrainingElem = StudyModeElem->FirstChildElement();//AVTraing	
		TiXmlElement *CurrentLevelElem = NULL;
		TiXmlElement *TestPersonCountElem = NULL;
		TiXmlElement *PassLineElem = NULL;
		TiXmlElement *ExcellentLineElem = NULL;
		TiXmlElement *LevelLineXItem = NULL;
		  		
		if(Smode == 0 )//"AVT"
		{
			CurrentLevelElem = FirstTrainingElem->FirstChildElement();			
		}
		else if(Smode == 1 )// "VPT" 
		{
			CurrentLevelElem = FirstTrainingElem->NextSiblingElement()->FirstChildElement();			
		}
		else if(Smode == 2 ) //"LST"
		{
			CurrentLevelElem = FirstTrainingElem->NextSiblingElement()->NextSiblingElement()->FirstChildElement();			
		}
		if(CurrentLevelElem != NULL)
		{
			TestPersonCountElem = CurrentLevelElem->NextSiblingElement();
			PassLineElem = TestPersonCountElem->NextSiblingElement();
			ExcellentLineElem = PassLineElem->NextSiblingElement();
			LevelLineXItem = ExcellentLineElem->NextSiblingElement();
			
			if(strcasecmp( NodeElemName.c_str() , "CurrentLevel") == 0)
			{
				return CurrentLevelElem;
			}			
			else if(strcasecmp( NodeElemName.c_str() , "TestPersonCount") == 0)
			{
				return TestPersonCountElem;
			}
			else if(strcasecmp( NodeElemName.c_str() , "PassLine") == 0)
			{
				return PassLineElem;
			}
			else if(strcasecmp( NodeElemName.c_str() , "ExcellentLine") == 0)
			{
				return ExcellentLineElem;
			}
			else if(strcasecmp( NodeElemName.c_str() , "LevelLine") == 0)
			{
				for(int index = 0  ; index < 12 && LevelLineXItem != NULL ; index++)
				{
					if(index == LevelIndex)
						break;
					LevelLineXItem = LevelLineXItem->NextSiblingElement();
				}
				return LevelLineXItem;
			}
			return NULL;
		}
		
	}
}

////////////////AVT////////////////
int SettingXml::GetCurrentLevel(int Smode )
{
  return avSet[Smode].CurrentLevel;
}

int SettingXml::SetCurrentLevel(int Smode, int iLevel)
{
	if(pRootElement != NULL)
	{		
		TiXmlElement *CurrentLevelElem = GetElem(Smode ,"CurrentLevel" );
		char cLevelIndex[3];
		sprintf(cLevelIndex, "%d" , iLevel);
		if(CurrentLevelElem != NULL)
		{
			CurrentLevelElem->FirstChild()->SetValue(cLevelIndex);		
			myDocument->SaveFile();
			return 0;
		}
	}
	return -1;
}

int SettingXml::GetTestPersonCount(int Smode )
{
  return avSet[Smode].TestPersonCount;
}

int SettingXml::SetTestPersonCount(int Smode, int TestPersonCount)
{
	if(pRootElement != NULL)
	{
		
		TiXmlElement *TestPersonCountElem = GetElem(Smode ,"TestPersonCount");
		char cTestPersonCount[3];
		sprintf(cTestPersonCount, "%d" , TestPersonCount);
		if(TestPersonCountElem != NULL)
		{
			TestPersonCountElem->FirstChild()->SetValue(cTestPersonCount);
			
			myDocument->SaveFile();
			return 0;
		}
	}
	return -1;
}


double SettingXml::GetPassLine(int Smode )
{
  return avSet[Smode].PassLine;
}

int SettingXml::SetPassLine(int Smode, double PassLine)
{
	if(pRootElement != NULL)
	{		
		TiXmlElement *PassLineElem = GetElem(Smode ,"PassLine");
		char cPassLine[3];
		sprintf(cPassLine, "%2.1f" , PassLine);
		if(PassLineElem != NULL)
		{
			PassLineElem->FirstChild()->SetValue(cPassLine);
			
			myDocument->SaveFile();
			return 0;
		}
	}
	return -1;
}

double SettingXml::GetExcellentLine(int Smode )
{
  return avSet[Smode].ExcellentLine;
}

int SettingXml::SetExcellentLine(int Smode, double ExcellentLine)
{
	if(pRootElement != NULL)
	{		
		TiXmlElement *ExcellentLineElem = GetElem(Smode ,"ExcellentLine");
		char cExcellentLine[3];
		sprintf(cExcellentLine, "%2.1f" , ExcellentLine);
		if(ExcellentLineElem != NULL)
		{
			ExcellentLineElem->FirstChild()->SetValue(cExcellentLine);
			
			myDocument->SaveFile();
			return 0;
		}
	}
	return -1;
}


int SettingXml::GetLevelLine(int Smode, int LevelIndex)
{
  return avSet[Smode].LevelLine[LevelIndex];
}

int SettingXml::SetLevelLine(int Smode, int LevelIndex, int LevelLine)
{
	if(pRootElement != NULL)
	{		
		TiXmlElement *LevelLineElem ;
		if(Smode == 0)
			LevelLineElem = GetElem(Smode ,"LevelLine" ,LevelIndex-1);
		else
			LevelLineElem = GetElem(0 ,"LevelLine");
		
		char cLevelLine[3];
		sprintf(cLevelLine, "%d" , LevelLine);
		if(LevelLineElem != NULL)
		{
			LevelLineElem->FirstChild()->SetValue(cLevelLine);
			
			myDocument->SaveFile();
			return 0;
		}
	}
	return -1;
}

int SettingXml::GetSpeedMode(int Smode)
{
	return avSet[Smode].SpeedMode;
}

int SettingXml::SetSpeedMode(int Smode, int SpeedMode)
{
	if(pRootElement != NULL)
	{		
		TiXmlElement *LevelLineElem ;
		if(Smode == 1)
			LevelLineElem = GetElem(1 ,"LevelLine" );
		else
			return -1;
		
		char cLevelLine[3];
		sprintf(cLevelLine, "%d" , SpeedMode);
		if(LevelLineElem != NULL)
		{
			LevelLineElem->FirstChild()->SetValue(cLevelLine);
			
			myDocument->SaveFile();
			return 0;
		}
	}
	return -1;
}


////////////////AVT////////////////
	
/*
AVTrainningPartSetting* SettingXml::GetAVCourseSetting(string part)//<T>
{
  vector<AVTrainningPartSetting>::iterator iter;
    int i = 0;
    for( iter = VAVTrainningPartSetting.begin(); iter != VAVTrainningPartSetting.end(); ++i , ++iter)
    {
	int iFound = part.find(iter->ID);
	if (iFound != string::npos )//if(iter->StudyRecordInfoID == id)
	  return &VAVTrainningPartSetting[i];
	 
	
    }
    return NULL;
}
*/
