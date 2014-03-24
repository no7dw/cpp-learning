#ifndef __STUDY_RECORD_XML_H
#define __STUDY_RECORD_XML_H

// #include "tinystr.h"
// #include "tinyxml.h"
// #include "Types.h"
// 
// #include <iostream>
// #include <string.h>
// #include <vector> 

#include "XXml.h"

#define ID_MAX 11

using namespace std;
//学习记录
struct StudyRecordInfo{
		string StudyRecordInfoID;//学习记录ID
		string CourseID;//课程ID
		string CourseName;//课程ID
		int Study_Interval;//学习时长
		string Study_Time;//学习时间
		int Flower;//红花数
		int FirstGrade;	//第一次的学习评定
		
		double Study_Score;//主角的学习成绩		
		int UnAnswerCount;//主角的未答题目数
		int RCount;//主角的回答正确题目数
		int WCount;//主角的回答错误题目数 		
						
		int Study_PersonCount;//参与学习人数
		
		double PersonA_Score;	//配角A的学习成绩	
		int RCountA;//配角A的回答正确题目数	
		int WCountA;//配角A的回答错误题目数	
		int UnAnswerCountA;//配角A的未答题目数	
		
		double PersonB_Score;//配角B的学习成绩	
		int RCountB;//配角B的回答正确题目数	
		int WCountB;//配角B的回答错误题目数	
		int UnAnswerCountB;//配角B的未答题目数	
		
		StudyRecordInfo()
		{
			StudyRecordInfoID="";
			CourseID="";
			CourseName="";
			Study_Interval=0;
			Study_Time="";
			Flower=0;
			FirstGrade=0;
			
			Study_Score=0;			
			UnAnswerCount = 0;
			RCount=0;
			WCount=0;
						
			Study_PersonCount=1;
			
			PersonA_Score=0;
			RCountA=0;
			WCountA=0;
			UnAnswerCountA = 0;
			
			PersonB_Score=0;
			RCountB=0;
			WCountB=0;
			UnAnswerCountB = 0;
			
			//memset(&StudyRecordInfo , 0, sizeof(StudyRecordInfo ));
			
		}
	};
	

class StudyRecordXml: public XXml
{
public:

	StudyRecordXml();
	~StudyRecordXml();

private:
	vector <StudyRecordInfo> VStudyRecordInfoArray;
	int CurrentPart;
public:

	int LoadXml(const char *XmlFilePath);
	int SaveXml();

	///@Summary: 根据学习记录ID获取学习记录信息
	///@Param 1: 学习记录ID
	///@Return :学习记录信息结构体指针
	StudyRecordInfo* GetStudyRecordInfo(string id);//It shoule by <T>
	
	///@Summary: 获取学习记录	
	///@Return :学习记录结构体vector<StudyRecordInfo>指针
	vector <StudyRecordInfo>* GetStudyRecordInfo(); 
	
	///@Summay : 增加学习记录
	///@Param 1: 要增加的学习记录	
	///@Return : 返回是否成功 0 成功 -1失败
	int AddItem(StudyRecordInfo info);
	//bool SetAVCourseSetting(int part, AVTrainningPartSettingKind SettingKind, int value);
	

};
#endif