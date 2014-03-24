#ifndef __X_XML_H
#define __X_XML_H

#define PURE_XML_TEST

#ifndef PURE_XML_TEST
	#include <Utility/tinyxml/tinystr.h>
	#include <Utility/tinyxml/tinyxml.h>		
#else
	#include "tinystr.h"
	#include "tinyxml.h"
#endif

#include "Types.h"

#include <iostream>
#include <string.h>
#include <vector> 

//template <typename T>

class XXml
{
public:
// 	XXml(const char *XmlFilePath);
	XXml();
	~XXml();
	
	//T TobjV;
	
protected:
	TiXmlDocument *myDocument;
	char m_XmlFilePath[100];
	TiXmlElement *pFirstBookElem;
	TiXmlElement *pLastBookElem;
	TiXmlElement *pRootElement;
	
	int LoadXml(const char *XmlFilePath);
	int SaveXml();
	//int GetFirstChildValue(TiXmlElement *pElement, char *pValue);
public:

	// /*virtual */int LoadXml() = 0;
	
	//virtual T* GetInfo(string ID) = 0;
	
};
#endif