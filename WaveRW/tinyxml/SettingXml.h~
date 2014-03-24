#ifndef __SETTING_XML_H
#define __SETTING_XML_H

#include "XXml.h"

using namespace std;

//模块设置信息
typedef struct {
	int CurrentLevel;//当前阶段
	int TestPersonCount;//测试人数
	double PassLine;//及格门限
	double ExcellentLine;	//优秀门限
	int LevelLine[12];//每个过关门限（看图学单词，抒情朗读只用到[0])
	int SpeedMode;//速度模式(只适用于看图学单词)
	
}AVTSet;
//用户信息
typedef struct {
	string EquipSN;	//设备ID（用户ID）
	string avatar;//头像
	string username;//用户名
	string NetUserName;//pppoe网络用户名
	string NetPassWord;//pppoe网络密码
}UserInfo;
	
class SettingXml : public XXml
{
public:

	SettingXml();
	~SettingXml();

private:
	
	AVTSet avSet[5];
	UserInfo uinfo;
	
private:
	
	TiXmlElement* GetElem(int Smode , string NodeElemName, int LevelIndex = 0);
public:
	int LoadXml(const char *XmlFilePath);
////////////////System Setting////////////////
	
	//obsolete
	///@Summary: 获取用户头像		
	string GetAvatar();
	
	///@Summary: 获取用户名	
	string GetUserName();
	
	///@Summary: 设置用户头像
	///@Param 1: 用户头像路径
	///@Return : 返回是否成功 0 成功 -1失败
	int SetAvatar(string AvastarPath);
	
	///@Summary: 设置用户名
	///@Param 1: 用户名
	///@Return : 返回是否成功 0 成功 -1失败
	int SetUserName(string UserName);
	
	///@Summary: 获取用户信息	
	///@Return :用户信息结构体指针
	UserInfo* GetUserInfo();
	
	///@Summary: 设置用户名
	///@Param 1: pppoe网络用户名
	///@Param 1: pppoe网络用户密码
	///@Return : 返回是否成功 0 成功 -1失败
	int SetNetUserName_PassWord(string netUserName, string netPassWord);
	
////////////////System Setting////////////////	
	
////////////////AVT////////////////
	//Smode = 0 AudioVideo_TrainingMode
	//Smode = 1 ViewPitcure_TrainingMode
	//Smode = 2 LyricsSpeak_TrainingMode	
	
	///@Summary: 获取学习模式的当前阶段
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	int GetCurrentLevel(int Smode );
	
	///@Summary: 设置学习模式的当前阶段
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	///@Param 2: 当前阶段
	///@Return : 返回是否成功 0 成功 -1失败
	int SetCurrentLevel(int Smode, int iLevel);
	
	
	///@Summary: 获取学习模式的当前阶段
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	int GetTestPersonCount(int Smode );
	
	///@Summary: 设置学习模式的当前阶段
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	///@Param 2: 当前阶段
	///@Return : 返回是否成功 0 成功 -1失败
	int SetTestPersonCount(int Smode , int TestPersonCount);
	
	
	///@Summary: 获取学习模式的及格门限
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	double GetPassLine(int Smode );
	
	///@Summary: 设置学习模式的及格门限
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	///@Param 2: 及格门限
	///@Return : 返回是否成功 0 成功 -1失败
	int SetPassLine(int Smode , double PassLine);		
	
	///@Summary: 获取学习模式的优秀线
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	double GetExcellentLine(int Smode );
	
	///@Summary: 设置学习模式的优秀线
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	///@Param 2: 优秀线
	///@Return : 返回是否成功 0 成功 -1失败
	int SetExcellentLine(int Smode , double ExcellentLine);
		
	///@Summary: 获取学习模式的升级门限
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	//LevelIndex start from 1
	int GetLevelLine(int Smode  ,int LevelIndex );
	
	///@Summary: 设置学习模式的升级门限
	///@Param 1: 学习模式：0 视听选答 1 看图学单词 2 抒情朗读
	///@Param 2: 升级门限
	///@Param 3: 阶段
	///@Return : 返回是否成功 0 成功 -1失败
	//LevelIndex start from 1
	int SetLevelLine(int Smode , int LevelIndex  , int LevelLine );
	
	///@Summary: 获取学习模式的速度模式
	///@Param 1: 学习模式：1 看图学单词 （目前仅仅看图学单词用）
	int GetSpeedMode(int Smode );
	
	///@Summary: 设置学习模式的当前阶段
	///@Param 1: 学习模式：1 看图学单词 （目前仅仅看图学单词用）
	///@Param 1: 速度模式 ：常速 0 变速 1 
	///@Return : 返回是否成功 0 成功 -1失败
	int SetSpeedMode(int Smode , int SpeedMode);
	
////////////////AVT////////////////

////////////////VPT////////////////
	
////////////////VPT////////////////	
    



};
#endif

