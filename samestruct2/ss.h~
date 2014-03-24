#ifndef __RESOURCE_PACKAGE_H
#define __RESOURCE_PACKAGE_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const short ID_SIZE = 48+1; //由于软件升级，该为存取软件升级包的Hash
const short  NAME_SIZE = 256;
const short  PATH_SIZE = 100+1;
const short  HASH_SIZE = 48+1;
const short  MAX_PATH  = 255;
struct CourseInfo{
	
	char ID[ID_SIZE];
	char Name[NAME_SIZE];
	char Path[PATH_SIZE];
	char Hash[HASH_SIZE];
	int Level;//1-12阶段
	int Grade;//优先级别
	int SendbySM;//那个模式的
	int Status;//状态 0 UNBOOK 1 BOOK 2 DOWNLOADING 3 COMPLETED
	int Last_Percent;
	CourseInfo()
	{
	    memset(ID,0,sizeof(ID));
	    memset(Name,0,sizeof(Name));
	    memset(Path,0,sizeof(Path));
	    memset(Hash,0,sizeof(Hash));	    
	    Level = 0;
	    Grade = 0;
	    SendbySM = 0;
	    Status = 1;
	    Last_Percent = 0;
	}
};
 

class ResourceFactory
{

private:
	CourseInfo m_CI;
public:
	virtual ~ResourceFactory();
public:
  
	ResourceFactory(const CourseInfo &CI);	
	static ResourceFactory* CreateInstance(const CourseInfo &CI);
	virtual int Book();
	

private:
	static ResourceFactory* _instance;
};


class SoftPackageFactory : public ResourceFactory
{
private:
	CourseInfo m_CI;	
public:
	virtual ~SoftPackageFactory();
public:
	SoftPackageFactory(const CourseInfo &CI);
	static ResourceFactory* CreateInstance(const CourseInfo &CI);
	int Book();
	
private:
	static SoftPackageFactory* _instance;
	
};

class AdvertisementFactory: public SoftPackageFactory
{
private:
	CourseInfo m_CI;
public:
	virtual ~AdvertisementFactory();	
public:
	AdvertisementFactory(const CourseInfo &CI);
	static SoftPackageFactory* CreateInstance(const CourseInfo &CI);
	int Book();
private:
	static AdvertisementFactory* _instance;
};
#endif

