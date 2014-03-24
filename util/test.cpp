#include "Util.h"
#include <stdio.h>
#include <string.h>
using namespace std;

int main(void)
{
	string strsrc = "##a#b#c#d#";
	string delims = "#";
	vector<string> vDest;
	splitString(strsrc ,delims ,vDest );
	for( vector<string>::iterator iter = vDest.begin(); iter != vDest.end() ; ++iter )
	{
		printf("%s\n" , (*iter).c_str() );
	}
	
}
