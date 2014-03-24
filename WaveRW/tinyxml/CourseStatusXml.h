#ifndef __COURSE_STATUS_XML_H
#define __COURSE_STATUS_XML_H

#include "XXml.h"

using namespace std;
//课程状态
typedef struct{
	string CourseID;//课程ID	
	int iStatus;//status(0 已下载 1 正在下载 2 预约 3 未预约 4 已学习 ) 
}CourseStatus;

class CourseStatusXml : public XXml
{
public:

	CourseStatusXml();
	~CourseStatusXml();
private:
	
	
	
	vector<CourseStatus> VStatus;	
	
	
	
private:
	//int GetCourseXmlStatus(string id , bool blnGetNew);
	
public:
	int LoadXml(const char *XmlFilePath);
	
	///@Summay : 根据课程ID获取课程状态
	///@Param 1: 课程ID
	///@Return : 返回是否成功 0 成功 -1失败
	int GetCourseStatus(string id);
	
	///@Summay : 更新课程状态
	///@Param 1: 课程ID
	///@Param 2: 课程状态
	///@Return : 返回是否成功 0 成功 -1失败
	int UpdateStatus(string id, int iStatus = 0);
	
	///@Summay : 增加课程状态
	///@Param 1: 要增加的课程状态	
	///@Return : 返回是否成功 0 成功 -1失败
	int AddItem(CourseStatus CI);
	
	///@Summay : 删除课程状态
	///@Param 1: 要删除的课程状态	
	///@Return : 返回是否成功 0 成功 -1失败
	int RemoveItem(string ID);



};
#endif
