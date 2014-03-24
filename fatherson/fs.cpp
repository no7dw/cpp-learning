#include "father.h"
#include "son.h"
int main()
{
	//father *pF;
	father *pF = new father();
	pF->printout();
	son *pS/* = new father()*/;
	pS->printout();
	
	return 0;
}
