#include <stdio.h>
#include "f.h"
//#include "s.h"
 #include "s1.h"

int main(void)
{

	s1 s12 ;
	//ps1->fun();
	s12.fun4();
	
	
///////////////////
	f *pfs1 = new s1();
	pfs1->fun();

	delete pfs1;
	pfs1=NULL;

	printf("pfs1 delete finished\n\n");
	
///////////////////

	
/*
	s *psf1 = new f();	//error invalid conversion from ‘f*’ to ‘s*’
	psf1->fun();

	delete psf1;
	psf1=NULL;

	printf("\n\n");
*/	
	
///////////////////
	
// 	s s1 ;
// 	s1.fun();
// 	s1.fun3();
// 	s1.fun4();
// 	printf("su_name:%s\t",s1.su_name);
// 	printf("\n\n");
// 	
// /////////////////

/*
	f f1 ;
	f1.fun();
	f1.fun2();
	printf("\n\n");
	
	ps1->pi();
	ps1->mi();
	ps1->pi();
	
	
	
	delete ps1;
	ps1=NULL;
*/
	
// 	s1 *pss1 = new s1();
// 	
// 	pss1->pi();
// 	pss1->mi();
// 	pss1->pi();
// 	
// 	delete pss1;
// 	pss1=NULL;
	
	printf("end\n");
}
