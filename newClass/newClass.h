#include <iostream>
#include <string.h>
using namespace std;

class newCT
{
public:
	newCT();
	~newCT();
private:
	int Id;
	string Name;
public:
	static int count;
public:
void	Init(int id, string name);
void	printout();

static void 	printcount();
};
