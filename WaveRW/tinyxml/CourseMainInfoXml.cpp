#include "CourseMainInfoXml.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "../Util.h"

using namespace std;

CourseMainInfoXml::CourseMainInfoXml()
{
	
}

CourseMainInfoXml::~CourseMainInfoXml()
{
}

int CourseMainInfoXml::LoadXml(const char *XmlFilePath)
{
	if(XXml::LoadXml(XmlFilePath)<0)
		return -1;
	
	myDocument = new TiXmlDocument(XmlFilePath);
	myDocument ->LoadFile();
		
	//begin read
	pRootElement = myDocument->RootElement();//CourseMainInfo
	if(pRootElement == NULL)
		return -1;
	
	strCourseMainInfoVersion = pRootElement->Attribute("version");
	
	//TiXmlElement *NewCourseIDItem = pRootElement->FirstChildElement();
	TiXmlElement *DelCourseIDItem = pRootElement->FirstChildElement();
// 	if(NewCourseIDItem->FirstChild() != NULL)
// 	{
// 		string strNewID = NewCourseIDItem->FirstChild()->Value();
// 		splitString( strNewID, "|", vNewID) ;
// 	}

	if(DelCourseIDItem->FirstChild() != NULL)
	{
		string strDelID = DelCourseIDItem->FirstChild()->Value();
		splitString( strDelID, ",", vDelID) ;
	}

	TiXmlElement *CourseListItem = DelCourseIDItem->NextSiblingElement();
	TiXmlElement *FirstCourseItem = CourseListItem->FirstChildElement();
	pFirstBookElem = FirstCourseItem;
	
	int index = 0;
	CourseMainInfo CMI;
	while ( FirstCourseItem != NULL )
	{
		TiXmlElement *FirstCourseIDItem = FirstCourseItem->FirstChildElement();
		CMI.CourseID = FirstCourseIDItem->FirstChild()->Value();
		
		TiXmlElement *FirstCourseNameItem = FirstCourseIDItem->NextSiblingElement();
		CMI.CourseName = FirstCourseNameItem->FirstChild()->Value();

		TiXmlElement *FirstCourseIntroItem = FirstCourseNameItem->NextSiblingElement();
		CMI.CourseIntro = FirstCourseIntroItem->FirstChild()->Value();
		
		TiXmlElement *FirstCourseScoreItem = FirstCourseIntroItem->NextSiblingElement();
		if(FirstCourseScoreItem->FirstChild() != NULL)
		{
			CMI.FirstScore = atoi(FirstCourseScoreItem->FirstChild()->Value());
		}
		else
		{
			CMI.FirstScore = 0;
		}
		TiXmlElement *FirstCourseRecentScoreItem = FirstCourseScoreItem->NextSiblingElement();
		if(FirstCourseRecentScoreItem->FirstChild() != NULL)
		{		
			CMI.RecentScore = atoi(FirstCourseRecentScoreItem->FirstChild()->Value());
		}
		else
		{
			CMI.RecentScore = 0;
		}

		TiXmlElement *FirstCourseFlowerItem = FirstCourseRecentScoreItem->NextSiblingElement();
		if(FirstCourseFlowerItem->FirstChild() != NULL)
		{		
			CMI.Flower = atoi(FirstCourseFlowerItem->FirstChild()->Value());
		}
		else
		{
			CMI.Flower = 0;
		}

		TiXmlElement *FirstCourseHashItem = FirstCourseFlowerItem->NextSiblingElement();
		CMI.Hash = FirstCourseHashItem->FirstChild()->Value();

		TiXmlElement *FirstCourseIsNewItem = FirstCourseHashItem->NextSiblingElement();
		CMI.IsNew = atoi(FirstCourseIsNewItem->FirstChild()->Value());

		index = index + 1;

		VCourseMainInfo.push_back(CMI);
		
		FirstCourseItem = FirstCourseItem->NextSiblingElement();
	}
	//end read
	
	cout <<"\nindex = "<< index << "#### Loop done ####" <<endl;
	
	return 1;
}

CourseMainInfo* CourseMainInfoXml::GetCourseInfo(string id)
{
    vector<CourseMainInfo>::iterator iter;
    int i = 0;
    for( iter = VCourseMainInfo.begin(); iter != VCourseMainInfo.end(); ++i , ++iter)
    {
	//int iFound = id.find(iter->CourseID);
	//if (iFound != string::npos )
	if(iter->CourseID == id)
	  return &VCourseMainInfo[i];
	 
	
    }
    return NULL;
}


vector<CourseMainInfo>* CourseMainInfoXml::GetCourseInfo()
{
	
	  return &VCourseMainInfo;
}

// VSID* CourseMainInfoXml::GetNewIDVector()
// {
// 	return &vNewID;
// }

VSID* CourseMainInfoXml::GetDelIDVector()
{
	return &vDelID;
}
string CourseMainInfoXml::GetCourseInfoVersion()
{
	return strCourseMainInfoVersion;
}

int CourseMainInfoXml::UpdateScore(string CourseID, int Score, int flower ,bool isFirst)
{
	if( pFirstBookElem != NULL && pRootElement != NULL)
        {
            TiXmlElement *FirstCourseItem = pFirstBookElem;
             while ( FirstCourseItem != NULL )
	    {			   
		TiXmlElement *FirstCourseIDItem = FirstCourseItem->FirstChildElement();
		string IDElem  = FirstCourseIDItem->FirstChild()->Value();
		
		    if( strcmp(IDElem.c_str() , CourseID.c_str()) ==0)
		    {			    						
			TiXmlElement *FirstCourseNameItem = FirstCourseIDItem->NextSiblingElement();
			
			TiXmlElement *FirstCourseIntroItem = FirstCourseNameItem->NextSiblingElement();			
			
			TiXmlElement *FirstCourseScoreItem = FirstCourseIntroItem->NextSiblingElement();					
			
			TiXmlElement *FirstCourseRecentScoreItem = FirstCourseScoreItem->NextSiblingElement();			
			
			TiXmlElement *FirstCourseFlowerItem = FirstCourseRecentScoreItem->NextSiblingElement();
			
			char cflower[2] = {0};
			sprintf(cflower, "%d" ,flower);
			FirstCourseFlowerItem->FirstChild()->SetValue(cflower); 
			
			char cscore[3] = {0};			
			sprintf(cscore, "%d" ,Score);			
			if(isFirst)
			{	
				if(FirstCourseScoreItem->FirstChild() != NULL)
				{
					FirstCourseScoreItem->FirstChild()->SetValue(cscore); 											
				}
				else
				{
					TiXmlText *pNewTextCoureScore = new TiXmlText(cscore);
					FirstCourseScoreItem->LinkEndChild(pNewTextCoureScore);					
				}
			}
			 	
			//first score is also recent score
			if(FirstCourseRecentScoreItem->FirstChild() != NULL)
			{
				FirstCourseRecentScoreItem->FirstChild()->SetValue(cscore);											
			}
			else
			{
				TiXmlText *pNewTextCoureScore = new TiXmlText(cscore);
				FirstCourseRecentScoreItem->LinkEndChild(pNewTextCoureScore);					
			}
			
						
			myDocument->SaveFile();
			return 0;
			
		    }
		    
		    FirstCourseItem = FirstCourseItem->NextSiblingElement();
	    }//not found
	    return -1;

        }
}
/*
int CourseMainInfoXml::UpdateNew(string CourseID, int isNew)
{
	if( pFirstBookElem != NULL && pRootElement != NULL)
        {
            TiXmlElement *FirstCourseItem = pFirstBookElem;
             while ( FirstCourseItem != NULL )
	    {			   
		TiXmlElement *FirstCourseIDItem = FirstCourseItem->FirstChildElement();
		string IDElem  = FirstCourseIDItem->FirstChild()->Value();
		
		    if( strcmp(IDElem.c_str() , CourseID.c_str()) ==0)
		    {			    						
			TiXmlElement *FirstCourseNameItem = FirstCourseIDItem->NextSiblingElement();
			
			TiXmlElement *FirstCourseIntroItem = FirstCourseNameItem->NextSiblingElement();			
			
			TiXmlElement *FirstCourseScoreItem = FirstCourseIntroItem->NextSiblingElement();					
			
			TiXmlElement *FirstCourseRecentScoreItem = FirstCourseScoreItem->NextSiblingElement();			
			
			TiXmlElement *FirstCourseFlowerItem = FirstCourseRecentScoreItem->NextSiblingElement();
			
			TiXmlElement *FirstCourseHashItem = FirstCourseFlowerItem->NextSiblingElement();		

			TiXmlElement *FirstCourseIsNewItem = FirstCourseHashItem->NextSiblingElement();
		
			char cisNew[2] = {0};
			sprintf(cisNew, "%d", isNew);
			if(FirstCourseIsNewItem->FirstChild() != NULL)
			{
				FirstCourseIsNewItem->FirstChild()->SetValue(cisNew); 											
			}
			else
			{
				TiXmlText *pNewTextCoureScore = new TiXmlText(cisNew);
				FirstCourseIsNewItem->LinkEndChild(pNewTextCoureScore);					
			}			
						
			myDocument->SaveFile();
			return 0;
			
		    }
		    
		    FirstCourseItem = FirstCourseItem->NextSiblingElement();
	    }//not found
	    return -1;

        }
}
*/
