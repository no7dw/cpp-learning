#include "father.h"
#include <stdio.h>
#include <iostream>
using namespace std;

father::father()
{
	pv = 1;
	pt = 2;
	pb = 3;
}

void father::printout()
{
	cout << "pv = " << pv << endl;
	cout << "pt = " << pt << endl;
	cout << "pb = " << pb << endl;
}
