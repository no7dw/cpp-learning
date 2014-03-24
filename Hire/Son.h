//#include <stdlib.h>
#include <string>
#include "Father.h"

using namespace std;

class Son : public Father
{
public:
	int Age;
public:
	Son(int id,string name,int age);
	~Son();
};
