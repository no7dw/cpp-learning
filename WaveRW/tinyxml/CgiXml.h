#ifndef __CGI_XML_H
#define __CGI_XML_H

// #include "tinystr.h"
// #include "tinyxml.h"
// #include "Types.h"
// 
// #include <iostream>
// #include <string.h>
// #include <vector> 
#include "XXml.h"

using namespace std;

typedef struct {
		string ID;//下载任务ID
		int Priority;//优先级别
		string Partition;//储存磁盘
		string Space;//磁盘大小
		string Name;//任务名称
		string Status;//任务状态
		double Size;//任务大小
		double Downloaded;//已下载大小
		string TimeLeft;//所剩时间
		string Percent;//百分比
		double DwRate;//下载速度
		double UpRate;//上传速度
		int Npeers;//peer数
		
	}JobInfo;
	
class CgiXML : public XXml
{
public:
	CgiXML();
	~CgiXML();
private:
	string DaemonStatus;
	int TorrentCount;
	vector<JobInfo> VJobInfo;
	
public:

	int LoadXml(const char *XmlFilePath);
	JobInfo* GetJobInfo(string id);
	
};
#endif