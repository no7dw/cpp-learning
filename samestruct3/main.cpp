#include "ss.h"


int main( void )
{
	ResourceFactory *pr1;
	CourseInfo CI;
	for(int i =0 ; i < 3; i++)
	{
		strcpy( CI.ID, "90011");
		printf("** 1 90011**\n");
		pr1 = ResourceFactory::CreateInstance(CI);
		pr1->Book();

		strcpy( CI.ID, "80011");
		printf("** 2 80011**\n");	
		pr1 = ResourceFactory::CreateInstance(CI);
		pr1->Book();
		

		strcpy( CI.ID, "111");	
		printf("** 3 111**\n");
		pr1 = ResourceFactory::CreateInstance(CI);
		pr1->Book();

		printf("=================%d repeat =================\n", i);
	}		
	delete pr1;
}
