#include "Son.h"
//#include "Father.h"
//#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	Son *aSon = new Son(1,"David",25);
//	Son *aSon = new Son(1,"",25);
	
	cout<< aSon->ID << endl;
	cout<< aSon->Name << endl;
	cout<< aSon->SueName << endl;
	cout<< aSon->Age << endl;

}
