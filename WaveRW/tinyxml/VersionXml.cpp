#include "VersionXml.h"
#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace std;

VersionXml::VersionXml()
{
	
}
VersionXml::~VersionXml()
{
}

int VersionXml::LoadXml(const char *XmlFilePath)
{
	if(XXml::LoadXml(XmlFilePath)<0)
		return -1;
	
	myDocument = new TiXmlDocument(XmlFilePath);
	myDocument ->LoadFile();
		
	pRootElement = myDocument->RootElement();//Versions
	if(pRootElement == NULL)
		return -1;


	TiXmlElement *FirstCourseListsVersionItem = pRootElement->FirstChildElement();//AVTrainning
 
	int iLvV_index = 0;
	
	while ( FirstCourseListsVersionItem != NULL )
	{
		TiXmlElement *FirstTrainingLevelVersion = FirstCourseListsVersionItem->FirstChildElement();//LVx
		for(int col = 0 ; col < 12 && FirstTrainingLevelVersion; col ++)
		{
			if( FirstTrainingLevelVersion->FirstChild() != NULL )
			{
				strLvVersion[iLvV_index][col] =  FirstTrainingLevelVersion->FirstChild()->Value() ;				
			}
			FirstTrainingLevelVersion=FirstTrainingLevelVersion->NextSiblingElement();
		}
		iLvV_index = iLvV_index + 1;

		FirstCourseListsVersionItem = FirstCourseListsVersionItem->NextSiblingElement();
	}
 
	//end read
	
	cout <<"\nindex = "<< iLvV_index << "#### Loop done ####" <<endl;
	
	return 1;
}

string VersionXml::GetLvVersion(int Smode , int level) const
{
	if(level<=0 || Smode< 0 )
		return "";
	
	return strLvVersion[Smode][level-1];
}

int VersionXml::SetLvVersion(int Smode, int level, string strVersion)
{
	if( pRootElement != NULL)
        {
		TiXmlElement *FirstCourseListsVersionItem = pRootElement->FirstChildElement();//AVTrainning
 
		int iLvV_index = 0;
		
		while ( FirstCourseListsVersionItem != NULL )
		{
			if(iLvV_index == Smode)
			{
				TiXmlElement *FirstTrainingLevelVersion = FirstCourseListsVersionItem->FirstChildElement();//LVx
				if( FirstTrainingLevelVersion)
				{
					for(int col = 1 ; col < level ; col ++)//start from 1~12
					{					
						FirstTrainingLevelVersion=FirstTrainingLevelVersion->NextSiblingElement();
					}
					if( FirstTrainingLevelVersion->FirstChild() != NULL )
					{
						FirstTrainingLevelVersion->FirstChild()->SetValue(strVersion.c_str()) ;
						myDocument->SaveFile();
						return 0;
					}
				}
				return -1;
			}
			iLvV_index = iLvV_index + 1;

			FirstCourseListsVersionItem = FirstCourseListsVersionItem->NextSiblingElement();
		}

        }
        return -1;
}
