#ifndef __SETTING_XML_H
#define __SETTING_XML_H

// #include "tinystr.h"
// #include "tinyxml.h"
// #include "Types.h"
// 
// #include <iostream>
// #include <string.h>
// #include <vector> 

#include "XXml.h"

using namespace std;

typedef enum {
		Level_UpgradeVal,
		PassScore,
		ExcellentScore
	}AVTrainningPartSettingKind;

	typedef struct {
		string ID;
		int	Level_UpgradeVal;
		int PassScore;
		int ExcellentScore;
	}AVTrainningPartSetting;
	//看起来重复了 
	
class SettingXml : public XXml
{
public:

	SettingXml();
	~SettingXml();


private:

	vector <AVTrainningPartSetting> VAVTrainningPartSetting;
	string MacAddress;
	
public:

	int LoadXml(const char *XmlFilePath);

	AVTrainningPartSetting* GetAVCourseSetting(string part);
	bool SetAVCourseSetting(int part, AVTrainningPartSetting Setting);
	bool SetAVCourseSetting(int part, AVTrainningPartSettingKind SettingKind, int value);

	string GetMacAddress();
	bool SetMacAddress(string mac);


};
#endif
