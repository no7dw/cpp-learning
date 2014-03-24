#ifndef __RESOURCE_PACKAGE_H
#define __RESOURCE_PACKAGE_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const short ID_SIZE = 48+1; 
const short  NAME_SIZE = 256;

struct CourseInfo{
	
	char ID[ID_SIZE];
	char Name[NAME_SIZE];	
	int SendbySM;
	CourseInfo()
	{
	    memset(ID,0,sizeof(ID));
	    memset(Name,0,sizeof(Name));	  
	    SendbySM = 0;
	   
	}
};
 

class ResourceFactory
{


public:
	virtual ~ResourceFactory(); 
	ResourceFactory(const CourseInfo &CI);	
	static ResourceFactory* CreateInstance(const CourseInfo &CI);
	virtual int Book();
	

private:
	static ResourceFactory* _instance;
public:
	CourseInfo m_CI;
};


class SoftPackageFactory : public ResourceFactory
{
public:
	virtual ~SoftPackageFactory();
	SoftPackageFactory(const CourseInfo &CI);
	static ResourceFactory* CreateInstance(const CourseInfo &CI);
	int Book();
	
private:
	static SoftPackageFactory* _instance;
// 	CourseInfo m_CI;
};

class AdvertisementFactory: public SoftPackageFactory
{
public:
	virtual ~AdvertisementFactory();	
public:
	AdvertisementFactory(const CourseInfo &CI);
	static SoftPackageFactory* CreateInstance(const CourseInfo &CI);
	int Book();
private:
	static AdvertisementFactory* _instance;
// 	CourseInfo m_CI;
};
#endif

