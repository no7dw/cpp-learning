#include <string>
#include <iostream>
//#include <stdlib>
#include "Father.h"
using namespace std;
	Father::Father(int id,string name, string sueName, int height)
	{
		this->ID=id;
		this->Name= name;
		this->SueName= sueName;
		this->Height =height;
	}

	Father::~Father()
	{}
