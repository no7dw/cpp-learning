#include "Vxml.h"
// #include <stdio.h>
// #include <iostream>
// #include <string.h>
#include "Convert.h"

using namespace std;

Vxml::Vxml()
{

}
Vxml::~Vxml()
{
	//delete	[]TiXmlElementArray1 ;
}

int Vxml::LoadXml(const char* XmlFilePath)
{
	if(XXml::LoadXml(XmlFilePath)<0)
		return -1;
	
	TiXmlDocument *myDocument = new TiXmlDocument(XmlFilePath);
	myDocument ->LoadFile();
		
	//begin read
	TiXmlElement *RootElement = myDocument->RootElement();//Resource

	//RSS	->	channel		->	title	->	Item

	TiXmlElement *NameItem = RootElement->FirstChildElement();
	TiXmlElement *FirstSentenceItem = NameItem->NextSiblingElement();
	

 

	int index = 0;
	
	while ( FirstSentenceItem != NULL )
	{
		TiXmlElement *StartElem = FirstSentenceItem->FirstChildElement();
		TiXmlElement *EndElem = StartElem->NextSiblingElement();				 		
					
		VStartTimeArray.push_back(  StartElem->FirstChild()->Value() );
		cout << VStartTimeArray[index].c_str() <<endl; 
				
		index = index + 1;
		//FirstSentenceItem =(TiXmlElement*) FirstSentenceItem->NextSibling();//the same effect
		FirstSentenceItem = FirstSentenceItem->NextSiblingElement();
		LastEndPoint =  EndElem->FirstChild()->Value();
	}

	//delete myDocument;//2011-5-13 bug
 
	//end read
	
	cout <<"\nindex = "<< index <<endl;
	//initilized  
// 	if (index>1) //this line should be ignore because this index may =1 . Adding this for Testing
	{
		 LastStartPoint  = VStartTimeArray[index-1] ;
		 FirstStartPoint = VStartTimeArray[0] ;
		ArraySize= index;
	}
	cout << "#### Loop done ####" <<endl;
	
	return 1;
}

string Vxml::QueryNextStartPointbyTime(const char *Time)
{
 
	int index=0;
	while( strcmp(Time,FirstStartPoint.c_str()) >0  && strcmp(LastStartPoint.c_str(),Time)  >0  )
	{
		if(strcmp(Time,VStartTimeArray[index].c_str())  >0  )
			index++;
		else if( 0 == strcmp(Time,VStartTimeArray[index].c_str())  )
		{
			//return  VStartTimeArray[index+1]; 
			return  VStartTimeArray[index+1] ;
		}
		else
		{
			//cout << "index " << index << endl;		
			//return  VStartTimeArray[index];//found	 VStartTimeArray[index] is the current session
			return  VStartTimeArray[index];
		}				
	}	
		
	if( 0==strcmp(Time,FirstStartPoint.c_str()) && (ArraySize > 1) )
	{	
		//return  VStartTimeArray[1];
		return  VStartTimeArray[1]; 
	}

	return "-1";
	
		
}

string Vxml:: QueryNextStartPointbyTime(long second,int frameIndex)
{
	 string strTime;
	 strTime = Convert::ToCharTime((int)second,frameIndex);
	 
	 //char ChTarget[ strlen( strTime.c_str() ) ];
	 char ChTarget[ 13 ];
	 strcpy(ChTarget,strTime.c_str());
	 
	 return QueryNextStartPointbyTime(ChTarget);
	 
}

string Vxml::QueryPrevStartPointbyTime(const char *Time)
{
 
	int index=0;
	while( strcmp(Time,FirstStartPoint.c_str()) >0  && strcmp(LastStartPoint.c_str(),Time)  >0  )
	{
		if(strcmp(Time,VStartTimeArray[index].c_str())  >0  )
			index++;
		else if( 0 == strcmp(Time,VStartTimeArray[index].c_str()) )
		{
			//return  VStartTimeArray[index-1];
			return  VStartTimeArray[index-1];
		}
		else
		{
			//cout << "index " << index << endl;
			if (index>=2)		
				return  VStartTimeArray[index-2];//found	 VStartTimeArray[index] is the current session
			else
				if(index == 1 )//BUG found when 
				    return VStartTimeArray[0];//FIXME::
				else
				    return "-1";
		}				
	}		
	
	if(0 == strcmp(Time, VStartTimeArray[0].c_str() ) )
	{
		return VStartTimeArray[0];
	}

	if( 0 == strcmp(Time,LastStartPoint.c_str()) && (ArraySize > 1) )
	{	
		return  VStartTimeArray[ArraySize-2];
	}
	
	if( strcmp(Time,LastStartPoint.c_str()) > 0 && strcmp(Time, LastEndPoint.c_str()) < 0 )//smaller than LastStartPoint or larger than LastEndPoint
	{	
		return  VStartTimeArray[ArraySize-1];
	}
	
	return "-1";//Not Found :reason:smaller than FistStartPoint or larger than LastStartPoint//BUG:://FIXME::Not Found :reason:smaller than FistStartPoint or larger than LastEndPoint		

}

string Vxml::QueryPrevStartPointbyTime(long second,int frameIndex)
{
	string strTime;
	 strTime = Convert::ToCharTime((int)second,frameIndex);
	 
	 //char ChTarget[ strlen( strTime.c_str() ) ];
	 char ChTarget[ 13];
	 strcpy(ChTarget,strTime.c_str());
	 
	 return QueryPrevStartPointbyTime(ChTarget);
	
}

string Vxml::QueryStartPointbyID(int ID)
{
	return VStartTimeArray[ID].c_str();
}

string Vxml::QueryAllStartPoint(const char *XmlFilePath)
{
	LoadXml ( XmlFilePath);

	string StrRet;	
	for(int index=0;index<ArraySize;index++)
	{
		if( strcmp(StrRet.c_str(),"")!=0)
		{
			StrRet.append("|");
		}
		else//first empth
		{
			//do nothing
		}
		//StrRet.append(VStartTimeArray[index]);
		StrRet.append(VStartTimeArray[index]);
	}
	return StrRet;
}
