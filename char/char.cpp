#include <string.h>
#include <iostream>
using namespace std;
int main(void)
{
	char string[10];
	const char *str="0123456789";

	strcpy(string,str);
	cout << string << endl;
	cout << string[9] <<endl;
}
