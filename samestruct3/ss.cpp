#include "ss.h"


ResourceFactory* ResourceFactory::_instance = 0;
SoftPackageFactory* SoftPackageFactory::_instance = 0;
AdvertisementFactory* AdvertisementFactory::_instance = 0;


ResourceFactory::~ResourceFactory()
{	
	printf("** deconstructing ResourceFactory **\n");
	if(!_instance)
		delete _instance;
}

ResourceFactory:: ResourceFactory(const CourseInfo &CI)
{
	m_CI = CI;
	m_CI.SendbySM = 1;
	printf("** constructing ResourceFactory **\n");
}
int ResourceFactory::Book()
{		
	printf("Book Resource ID = %s \t SendbySM = %d \n", m_CI.ID, m_CI.SendbySM);	
	
}

ResourceFactory* ResourceFactory::CreateInstance(const CourseInfo &CI)
{
	if( strncmp(CI.ID, "9", 1)==0 )
	{
		printf("**call new SoftPackageFactory **\n");
		return SoftPackageFactory::CreateInstance(CI);
	}
	else if(  strncmp(CI.ID, "8", 1)==0 ) 
	{
		printf("**call new AdvertisementFactory **\n");
		return AdvertisementFactory::CreateInstance(CI);		
	}
	else  
	{
		printf("**call new ResourceFactory **\n");
		if( _instance == 0  )					 
				_instance = new ResourceFactory(CI);		
	}
	
	return _instance;
}

SoftPackageFactory::~SoftPackageFactory()
{ 
	printf("** deconstructing SoftPackageFactory **\n"); 
	if(!_instance)
		delete _instance;
}

SoftPackageFactory::SoftPackageFactory(const CourseInfo &CI): ResourceFactory(CI)
{
	m_CI = CI;
	m_CI.SendbySM = 9;
	printf("** constructing SoftPackageFactory **\n");
}

ResourceFactory* SoftPackageFactory::CreateInstance(const CourseInfo &CI)
{
	if(_instance == 0)
	{
		printf("** new SoftPackageFactory **\n");
		_instance = new SoftPackageFactory(CI);
	}
	
	return _instance;
}


int SoftPackageFactory::Book()
{
	printf("book SoftPackage ID = %s \t SendbySM = %d \n", m_CI.ID, m_CI.SendbySM);
	
}

AdvertisementFactory::~AdvertisementFactory()
{ 
	printf("** deconstructing AdvertisementFactory **\n"); 
	if(!_instance)
		delete _instance;
}

AdvertisementFactory::AdvertisementFactory(const CourseInfo &CI): SoftPackageFactory(CI)
{
	m_CI = CI;
	m_CI.SendbySM = 8;
	printf("** constructing AdvertisementFactory **\n");
} 
SoftPackageFactory* AdvertisementFactory::CreateInstance(const CourseInfo &CI)
{
	if(_instance == 0 ) 
	{
		printf("** new AdvertisementFactory **\n");
		_instance = new AdvertisementFactory(CI);		
	}
		
	return _instance;

} 
int AdvertisementFactory::Book()
{
	printf("book Advertisement  ID = %s \t SendbySM = %d \n", m_CI.ID, m_CI.SendbySM);
	
}

