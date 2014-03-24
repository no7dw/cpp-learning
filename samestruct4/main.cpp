#include "ss.h"
#include "sImpl.h"

int main( void )
{
	ResourceFactory *pr1, *pr[3];
	CourseInfo CI;
	for(int i =0 ; i < 3; i++)
	{
		strcpy( CI.ID, "90011");
		printf("** 1 90011**\n");
		pr1 = ResourceFactory::psImpl_class->CreateInstance(CI);		
		pr1->Book();
		pr[0] = pr1;

		strcpy( CI.ID, "80011");
		printf("** 2 80011**\n");	
		pr1 = ResourceFactory::psImpl_class->CreateInstance(CI);
		pr1->Book();
		pr[1] = pr1;

		strcpy( CI.ID, "111");	
		printf("** 3 111**\n");
		pr1 = ResourceFactory::psImpl_class->CreateInstance(CI);
		pr1->Book();
		pr[2] = pr1;

		printf("=================%d repeat =================\n", i);
	}
	
	for(int i =0 ; i < 3; i++)
	{
		if(pr[i])	
			delete pr[i];
	}
	
	
}
