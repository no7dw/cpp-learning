#include "ss.h"

sImpl *ResourceFactory::psImpl_class = NULL;
ResourceFactory* ResourceFactory::_instance = 0;

ResourceFactory::ResourceFactory()
{	
	
}

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
	
	
	if( _instance == 0  )		
	{
			printf("**call new ResourceFactory **\n");
			_instance = new ResourceFactory(CI);		
	}
	return _instance;
}


