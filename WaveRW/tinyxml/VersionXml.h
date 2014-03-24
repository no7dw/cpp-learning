#ifndef __VERSION_XML_H
#define __VERSION_XML_H

// #include "tinystr.h"
// #include "tinyxml.h"
// #include "Types.h"
// 
// #include <iostream>
// #include <string.h>
// #include <vector> 
#include "XXml.h"

using namespace std;

class VersionXml: public XXml
{
public:
	VersionXml();
	~VersionXml();
private:
	
	string  strLvVersion[5][12];//row 5 column 12
	
public:

	int LoadXml(const char *XmlFilePath);		

	///@Summary: 根据学习模式，阶段，获取课程阶段版本信息
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	///@Param 2: 阶段 start from 1~12
	///@Return : 版本信息
	string GetLvVersion(int Smode , int level) const;
	
	///@Summay : 设置课程阶段版本信息
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	///@Param 2: 阶段
	///@Param 3: 版本 start from 1~12
	///@Return : 返回是否成功 0 成功 -1失败
	int SetLvVersion(int Smode , int level , string strVersion);

	
};
#endif