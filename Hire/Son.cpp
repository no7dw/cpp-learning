//#include <stdlib.h>
#include <string>
//#include "Father.h"
#include "Son.h"
using namespace std;

//Son::Son(int id,string name,int age): Father(id, "juping","Deng",170)
Son::Son(int id,string name,int age): Father(id, name,"Deng",170)
	{
		this->Age= age;
	}

Son::~Son()
	{
	}

