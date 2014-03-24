#ifndef __RESOURCE_PACKAGE_H
#define __RESOURCE_PACKAGE_H

#include "Struct.h"

 
class ResourceFactory
{
public:
	virtual ~ResourceFactory(); 
	ResourceFactory(const CourseInfo &CI);	
// 	virtual ResourceFactory* Creator();
	static ResourceFactory* CreateInstance(const CourseInfo &CI);
	virtual int Book();
	
protected:
	ResourceFactory();	
private:
	static ResourceFactory* _instance;
	
public:
// 	friend class sImpl;
	static sImpl *psImpl_class;
	CourseInfo m_CI;
};


#endif

