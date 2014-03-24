#ifndef __COURSE_MAIN_INFO_XML_H
#define __COURSE_MAIN_INFO_XML_H

// #include "tinystr.h"
// #include "tinyxml.h"
// #include "Types.h"
// 
// #include <iostream>
// #include <string.h>
// #include <vector> 
#include "XXml.h"
#include <vector>
using namespace std;

typedef vector<string> VSID;
//课程概要信息
typedef struct {
		string CourseID;//课程ID
		string CourseName;//课程名称
		string CourseIntro;//课程简介
		int FirstScore;// 第一次的学习评定
		int RecentScore;//最新一次的学习评定
		int Flower;//红花数
		string Hash;//课程种子Hash
		int IsNew;//是否是新的

	}CourseMainInfo;
	
class CourseMainInfoXml : public XXml
{
public:

	CourseMainInfoXml();
	~CourseMainInfoXml();
	
private:
   
	vector<CourseMainInfo> VCourseMainInfo;
 	//VSID vNewID;
  	VSID vDelID;
	string strCourseMainInfoVersion;
	
public:

	int LoadXml(const char *XmlFilePath);
 	//VSID* GetNewIDVector();
	///@Summary: 获取要删除的课程ID
	///@Return : vector<string>
 	VSID* GetDelIDVector();
	
	///@Summary: 获取课程概要信息的版本
	string GetCourseInfoVersion();
	
	///@Summary: 根据课程ID获取课程信息
	///@Param 1: 课程ID
	///@Return :课程信息结构体指针
	CourseMainInfo* GetCourseInfo(string id);
	
	///@Summary: 获取课程信息	
	///@Return :课程信息结构体vector<CourseMainInfo>指针	
	vector<CourseMainInfo>* GetCourseInfo();
	
	///@Summay : Update Score and flower 
	///@Param 1: CourseID
	///@Param 2: RecentGrade or FirstGrade
	///@Param 3: flowercount
	///@Param 4: true stands for update FirstGrade , false stands for update RecentGrade
	
	///@Summay : 更新课程成绩与红花数
	///@Param 1: 课程ID
	///@Param 2: 成绩
	///@Param 3: 红花数
	///@Param 4: 是否是首次成绩，如果是，则更新首次评定，否则更新最新一次评定
	///@Return : 返回是否成功 0 成功 -1失败
	int UpdateScore(string CourseID, int Score, int flower ,bool isFirst);
	//int UpdateNew(string CourseID, int isNew);
	
	

};
#endif
