#include "CourseStatusXml.h"
#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace std;

CourseStatusXml::CourseStatusXml()
{
    
    
}

CourseStatusXml::~CourseStatusXml()
{
    
}
int CourseStatusXml::LoadXml(const char *XmlFilePath)
{
	if(XXml::LoadXml(XmlFilePath)<0)
		return -1;
	
	myDocument = new TiXmlDocument(XmlFilePath);
	myDocument ->LoadFile();
		
	//begin read
	TiXmlElement *RootElement = myDocument->RootElement();//CourseStatus
	if(RootElement == NULL)
		return -1;
	else
	    pRootElement = RootElement;
	

	TiXmlElement *FirstCourseItem = RootElement->FirstChildElement();
	pFirstBookElem = FirstCourseItem;
	pLastBookElem = pFirstBookElem;
	
	int index = 0;
	CourseStatus CS;
	while ( FirstCourseItem != NULL )
	{
		CS.CourseID = FirstCourseItem->Attribute("ID");
//		TiXmlElement *FirstPartLevel_UpgradeValItem = FirstPartItem->NextSiblingElement();
		TiXmlElement *FirstCourseNameItem = FirstCourseItem->FirstChildElement();
		CS.iStatus =atoi( FirstCourseItem->FirstChild()->Value());

		index = index + 1;

		VStatus.push_back(CS);
		
		FirstCourseItem = FirstCourseItem->NextSiblingElement();
		if(FirstCourseItem != NULL)//FIXME::need to make sure it's not NULL
		    pLastBookElem = FirstCourseItem; //BUG:: It maybe NULL
	}
// 	

	//end read
	
	cout <<"\nindex = "<< index << "#### Loop done ####" <<endl;
	
	return 1;
}



int CourseStatusXml::GetCourseStatus(string id)
{
    //return GetCourseXmlStatus(id,false);
    vector<CourseStatus>::iterator iter;
    int i = 0;
    for( iter = VStatus.begin(); iter != VStatus.end(); ++i , ++iter)
    {
	//int iFound = id.find(iter->CourseID);
	//if (iFound != string::npos )
	if(iter->CourseID == id)
	{	     
		return VStatus[i].iStatus;	 	
	}
    }
}

/*
int CourseStatusXml::GetCourseXmlStatus(string id , bool blnGetNew)
{
    vector<CourseStatus>::iterator iter;
    int i = 0;
    for( iter = VStatus.begin(); iter != VStatus.end(); ++i , ++iter)
    {
	int iFound = id.find(iter->CourseID);
	if (iFound != string::npos )//if(iter->StudyRecordInfoID == id)
	{
	    if(!blnGetNew)
		return VStatus[i].iStatus/10;	 	
	    else	
		return VStatus[i].iStatus%10;	 	
	}
    }
    return -1;
}
*/

/*
bool CourseStatusXml::IsCourseNew(string id)
{
    int iRet = GetCourseXmlStatus(id,true);
    if (iRet==0)
	return false;
    else	
	return true;
}
*/
int CourseStatusXml::AddItem(CourseStatus CI)
{
	if( pRootElement == NULL && pLastBookElem == NULL)
	{
	    LoadXml(m_XmlFilePath);
	}
	if( pRootElement == NULL && pLastBookElem == NULL)//now we find out that no such file and we will make a new one
	{
	    //InitBookList();
	    //LoadXml();
	    return -1;
	}
	if( pRootElement != NULL /*&& pLastBookElem != NULL*/)
	{
	    TiXmlElement *pNewElemCourse = new TiXmlElement("Course");		
	    pNewElemCourse->SetAttribute("ID",CI.CourseID.c_str());
	    
	    char iSta[3] ;
	    sprintf(iSta, "%d" , CI.iStatus);
	    TiXmlText *pNewElemStatusText = new TiXmlText(iSta);	    	   	    
	    pNewElemCourse->LinkEndChild(pNewElemStatusText);
	    
	    pRootElement->LinkEndChild(pNewElemCourse);//adding it to the LastBookElem
	    pLastBookElem = pNewElemCourse;
	    printf("[%s:%d]:%s()- #### - !!\n",__FILE__,__LINE__,__func__);
	    myDocument->SaveFile();
	    return 0;
	}
	else
	    return -1;
}

int CourseStatusXml::RemoveItem(string ID)
{
	if( pRootElement == NULL && pLastBookElem == NULL)
	{
	    LoadXml(m_XmlFilePath);
	}
	
	if( pFirstBookElem != NULL && pRootElement != NULL)
	{
	    TiXmlElement *FirstCourseItem = pFirstBookElem;
	    while ( FirstCourseItem != NULL )
	    {				   
		    string IDElem = FirstCourseItem->Attribute("ID");
		    if( strcmp(IDElem.c_str() , ID.c_str()) ==0)
		    {
			pRootElement->RemoveChild(FirstCourseItem);
			myDocument->SaveFile();
			return 0;
			
		    }
		    
		    FirstCourseItem = FirstCourseItem->NextSiblingElement();
	    }//not found
	    return -1;
	     
	}
	else
	{
		return -1;
	}
}

int CourseStatusXml::UpdateStatus(string id, int iStatus)
{
	if( pFirstBookElem != NULL && pRootElement != NULL)
        {
            TiXmlElement *FirstCourseItem = pFirstBookElem;
             while ( FirstCourseItem != NULL )
	    {				   
		    string IDElem = FirstCourseItem->Attribute("ID");
		    if( strcmp(IDElem.c_str() , id.c_str()) ==0)
		    {
			/*
			int iv =atoi( FirstCourseItem->FirstChild()->Value());
			char civ[3] = {0};
			
			if (iStatus == 1)
			{				
				iv = iv / 10 * 10 + 1;				 
			}
			else
			{
				iv = iv / 10 * 10 + 0;				  
			}
			sprintf(civ , "%d" , iv);
			*/
			char civ[2] = {0};
			sprintf(civ , "%d" , iStatus);
			
			FirstCourseItem->FirstChild()->SetValue(civ); 	
			myDocument->SaveFile();
			return 0;
			
		    }
		    
		    FirstCourseItem = FirstCourseItem->NextSiblingElement();
	    }//not found
	    return -1;

        }
}
