#ifndef __S_IMPL_H
#define __S_IMPL_H

#include "Struct.h"
#include "ss.h"
#include "soft.h"
#include "ad.h"

// class ResourceFactory;
// class SoftPackageFactory;
// class AdvertisementFactory;

class sImpl
{
public:
	//friend class ResourceFactory;
	static ResourceFactory* CreateInstance(const CourseInfo &CI);
	
};

#endif
