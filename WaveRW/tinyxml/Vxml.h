#ifndef __V_XML_H
#define __V_XML_H

// #include "tinystr.h"
// #include "tinyxml.h"
// #include <iostream>
// #include <string.h>
// #include <vector>
#include "XXml.h"

using namespace std;

//#define MAXARRAYSIZE 1000

class Vxml : public XXml
{
public:
	Vxml();
	~Vxml();
private:
 
	//TiXmlElement *TiXmlElementArray1[MAXARRAYSIZE]; // 指针数组 存放Element
 	//char *StartTimeArray[MAXARRAYSIZE]; // 存放开始时间
 	
 	string LastStartPoint;
 	string FirstStartPoint;
	string LastEndPoint;
 	int ArraySize;
	vector <TiXmlElement *> VTiXmlElementArray1; // Vector指针数组 存放Element
	vector <string> VStartTimeArray;

public:
	int LoadXml(const char *XmlFilePath);
	
	///@Summary:查询下一句的开始点
	///@Param 1: 时间点
	string QueryNextStartPointbyTime(const char *Time);
	
	///@Summary:查询下一句的开始点
	///@Param 1: 时间
	///@Param 2: 侦
	string QueryNextStartPointbyTime(long second,int frameIndex);	
	
	///@Summary:查询上一句的开始点
	///@Param 1: 时间点
	string QueryPrevStartPointbyTime(const char *Time);
	
	///@Summary:查询上一句的开始点
	///@Param 1: 时间
	///@Param 2: 侦
	string QueryPrevStartPointbyTime(long second,int frameIndex);
	
	///@Summary:查询当前时间所属的分句开始点
	///@Param 1: 时间点
	string QueryCurrStartPointbyTime(const char *Time);				//查询当前的开始点
	
	///@Summary:根据ID查询（第N句）开始点
	///@Param 1: 时间	
	string QueryStartPointbyID(int ID);

	///@Summary: 获取xml文件的所有开始点
	///@Param 1: xml文本路径	
	///@Return : 所有开始点, 以“|”隔开
	string QueryAllStartPoint(const char *XmlFilePath);

};

#endif
