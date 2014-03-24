#ifndef __AD_PACKAGE_H
#define __AD_PACKAGE_H
#include "soft.h"
class AdvertisementFactory: public SoftPackageFactory
{
public:
	virtual ~AdvertisementFactory();	
public:
	AdvertisementFactory(const CourseInfo &CI);
	static AdvertisementFactory* CreateInstance(const CourseInfo &CI);
	int Book();
protected:
	AdvertisementFactory();
private:
	static AdvertisementFactory* _instance;
// 	CourseInfo m_CI;
};
#endif