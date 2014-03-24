#ifndef __NOTIFY_XML_H
#define __NOTIFY_XML_H

#include "XXml.h"

using namespace std;
//通知公告
struct Notif{
	string Notif_ID;//通知公告ID
	string Title;//标题
	string Content;//内容
	string StartTime;//有效开始时间（发布时间）
	string EndTime;//有效结束时间
	//int Readed;//是否已读
	Notif()
	{
		Notif_ID="";
		Title="";
		Content="";
		StartTime="";
		EndTime="";		
		//Readed=0;
	}
};

class NotifyXml: public XXml
{
public:
	
	NotifyXml();
	
	~NotifyXml();
private:
	string strVersion;
	
public:
	int LoadXml(const char *XmlFilePath);
	
	///@Summary: 根据通知公告ID获取通知公告信息
	///@Param 1: 通知公告ID
	///@Return :通知公告信息结构体指针
	vector <Notif>* GetNotif();
	
	///@Summary: 获取通知公告	
	///@Return :通知公告结构体vector< Notif>指针
	//vector <Notif>* GetUnReadNotif();
	
	///@Summay : 增加通知公告
	///@Param 1: 要增加的通知公告	
	///@Return : 返回是否成功 0 成功 -1失败
	int AddItem(const Notif &notif);
	
	///@Summay : 删除通知公告
	///@Param 1: 要删除的通知公告	
	///@Return : 返回是否成功 0 成功 -1失败
	int RemoveItem(string notif_ID);
	
	///@Summay : 更新通知公告的是否已读
	///@Param 1: 通知公告ID
	///@Param 2: 是否已读 	0 未读 1 已读 
	///@Return : 返回是否成功 0 成功 -1失败
	//int UpdateReaded(string notif_ID, int readed  = 1);
	
	///@Summary: 获取通知公告信息的版本
	string GetNoticeListVersion();
	
private:
	
	vector <Notif> VNotif;
	vector <Notif> VUnReadNotif;
	int NotifListSize;
	
	
	int LoadXml();
    
};

#endif