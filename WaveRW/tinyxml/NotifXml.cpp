#include "NotifXml.h"

NotifyXml::NotifyXml ()
{
	
}


NotifyXml::~NotifyXml()
{
	printf("NotifyXml::~NotifyXml()()\n");
}

int NotifyXml::LoadXml(const char *XmlFilePath)
{
	if(XXml::LoadXml(XmlFilePath)<0)
		return -1;
	
	myDocument = new TiXmlDocument(XmlFilePath);
	myDocument ->LoadFile();
		
	//begin read
	pRootElement = myDocument->RootElement();//Notification
	if(pRootElement == NULL)
		return -1;
	if(pRootElement->FirstAttribute() != NULL)
		strVersion = pRootElement->Attribute("version");
	
	TiXmlElement *FirstNotifElem = pRootElement->FirstChildElement();//Notif
	pFirstBookElem = FirstNotifElem;
	pLastBookElem = pFirstBookElem;		
	
	int index = 0;	
	Notif notif;
	
	while ( FirstNotifElem != NULL )
	{
		TiXmlElement *IDItem = FirstNotifElem->FirstChildElement();
		notif.Notif_ID = IDItem->FirstChild()->Value();
		
		TiXmlElement *TitleItem = IDItem->NextSiblingElement();
		notif.Title = TitleItem->FirstChild()->Value();
		
		TiXmlElement *ContentItem = TitleItem->NextSiblingElement();
		notif.Content = ContentItem->FirstChild()->Value();
		
		TiXmlElement *StartTimeItem = ContentItem->NextSiblingElement();
		notif.StartTime = StartTimeItem->FirstChild()->Value();
		
		TiXmlElement *EndTimeItem = StartTimeItem->NextSiblingElement();
		notif.EndTime = EndTimeItem->FirstChild()->Value();
		/*
		TiXmlElement *ReadedItem = EndTimeItem->NextSiblingElement();
		notif.Readed = atoi(ReadedItem->FirstChild()->Value());
		
		if(notif.Readed==0)
			VUnReadNotif.push_back(notif);
		*/
		
		VNotif.push_back(notif);
		  
		index = index + 1;		 
		 
		FirstNotifElem = FirstNotifElem->NextSiblingElement();
		if(FirstNotifElem != NULL)
		    pLastBookElem = FirstNotifElem; 
		
	}

	NotifListSize = index;
	
	cout <<"\nindex = "<< index << "#### Loop done ####" <<endl;
	
	return 0;
}

vector <Notif>* NotifyXml::GetNotif()
{
	return &VNotif;
}
/*
vector <Notif>* NotifyXml::GetUnReadNotif()
{
	return &VUnReadNotif;
}
*/
int NotifyXml::AddItem ( const Notif &notif )
{
	if( pRootElement == NULL/* && pLastBookElem == NULL*/)
        {
            LoadXml(m_XmlFilePath);
        }
	if( pRootElement != NULL /*&& pLastBookElem != NULL*/)
	{
	    TiXmlElement *pNewElemNotif = new TiXmlElement("Notice");		
	    
	    
	    TiXmlElement *pNewElemNotifID = new TiXmlElement("ID");	
	    TiXmlText *pNewTextNotifID = new TiXmlText(notif.Notif_ID.c_str());
	    pNewElemNotifID->LinkEndChild(pNewTextNotifID);
	    pNewElemNotif->LinkEndChild(pNewElemNotifID);
	    
	    TiXmlElement *pNewElemNotifTitle = new TiXmlElement("Title");	
	    TiXmlText *pNewTextNotifTitle = new TiXmlText(notif.Title.c_str());
	    pNewElemNotifTitle->LinkEndChild(pNewTextNotifTitle);
	    pNewElemNotif->LinkEndChild(pNewElemNotifTitle);
	    
	    TiXmlElement *pNewElemNotifContent = new TiXmlElement("Content");	
	    TiXmlText *pNewTextNotifContent = new TiXmlText(notif.Content.c_str());
	    pNewElemNotifContent->LinkEndChild(pNewTextNotifContent);
	    pNewElemNotif->LinkEndChild(pNewElemNotifContent);
	    
	    TiXmlElement *pNewElemNotifStartTime = new TiXmlElement("PubTime");	
	    TiXmlText *pNewTextNotifStartTime = new TiXmlText(notif.StartTime.c_str());
	    pNewElemNotifStartTime->LinkEndChild(pNewTextNotifStartTime);
	    pNewElemNotif->LinkEndChild(pNewElemNotifStartTime);
	    
	    TiXmlElement *pNewElemNotifEndTime = new TiXmlElement("EndTime");		  
	    TiXmlText *pNewTextNotifEndTime = new TiXmlText(notif.EndTime.c_str());
	    pNewElemNotifEndTime->LinkEndChild(pNewTextNotifEndTime);
	    pNewElemNotif->LinkEndChild(pNewElemNotifEndTime);
/*	    
	    TiXmlElement *pNewElemNotifGrade = new TiXmlElement("Readed");	
	    char cReaded[2] ;
	    sprintf(cReaded, "%d" , notif.Readed);
	    TiXmlText *pNewTextNotifGrade = new TiXmlText(cReaded);
	    pNewElemNotifGrade->LinkEndChild(pNewTextNotifGrade);
	    pNewElemNotif->LinkEndChild(pNewElemNotifGrade);
*/	    
	    
	    //pLastBookElem->LinkEndChild(pNewElemNotif);//adding it to the LastBookElem
	    pRootElement->LinkEndChild(pNewElemNotif);//adding it to the LastBookElem
	    pLastBookElem = pNewElemNotif;
	    printf("[%s:%d]:%s()- #### - !!\n",__FILE__,__LINE__,__func__);
	    if(myDocument == NULL)
	    {
		perror("myDocument == NULL");	
		return -1;
	    }
	    
	    myDocument->SaveFile();
	    return 0;
	}
	else
	    return -1;
}

int NotifyXml::RemoveItem ( string notif_ID )
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
                    TiXmlElement *IDElem = FirstCourseItem->FirstChildElement();
		    string strID = IDElem->FirstChild()->Value();
		    
                    if( strID == notif_ID)
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

string NotifyXml::GetNoticeListVersion()
{
	return strVersion;
}


/*
int NotifyXml::UpdateReaded ( string notif_ID , int readed  )
{
	if( pFirstBookElem != NULL && pRootElement != NULL)
        {
            TiXmlElement *FirstCourseItem = pFirstBookElem;
            while ( FirstCourseItem != NULL )
            {
                    TiXmlElement *IDElem = FirstCourseItem->FirstChildElement();
		    string strID = IDElem->FirstChild()->Value();
		    
                    if( strID == notif_ID)
                    {
                        TiXmlElement *ReadedElem  = IDElem->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement();
			if (readed == 1)		
				ReadedElem->FirstChild()->SetValue("1");  //readed
			else
				ReadedElem->FirstChild()->SetValue("0");  //unread
				
                        myDocument->SaveFile();
                        return 0;

                    }

                    FirstCourseItem = FirstCourseItem->NextSiblingElement();
            }//not found
            return -1;

        }
}
*/