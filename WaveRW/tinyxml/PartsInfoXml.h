#ifndef __PARTSINFO_XML_H
#define __PARTSINFO_XML_H

// #include "tinystr.h"
// #include "tinyxml.h"
// #include "Types.h"
// 
// #include <iostream>
// #include <string.h>
// #include <vector> 
#include "XXml.h"

using namespace std;
//阶段信息
typedef struct {
		string PartID;//阶段ID
		string PartName;//该阶段的阶段名称
		int Flowers;//该阶段所获得红花数
		int CourseCount;//该阶段的课程数目 
		int CouseLearned;//该阶段已学习课程
		string Grade_UpdateTime;//该阶段的升级所用时间
		string Study_Time;//该阶段的学习时间
		int Study_Times;//该阶段学习次数
	}PartInfo;
	
class PartsInfoXml : public XXml
{
public:

	PartsInfoXml();
	~PartsInfoXml();

private:
	vector<PartInfo> VPartInfo;

	
public:

	int LoadXml(const char *XmlFilePath);

	///@Summary: 根据阶段ID获取阶段信息
	///@Param 1: 阶段ID
	///@Return :阶段信息结构体指针
	PartInfo* GetPartInfo(string part);
	
	///@Summay : 更新阶段信息
	///@Param 1: 阶段ID
	///@Param 2: 阶段信息结构体
	///@Return : 返回是否成功 true 成功 false失败
	bool UpdatePartInfo(string partID, PartInfo &partinfo);
	//bool SetAVCourseSetting(int part, AVTrainningPartSettingKind SettingKind, int value);

	

};
#endif
