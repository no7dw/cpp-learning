#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
void UTIL_String_Replace(string &srcString, const string &strfind, const string &targetString)
{
	
	for(int pos = srcString.find(strfind.c_str());pos!=string::npos;)
	{
		srcString.replace(pos, strlen(targetString.c_str()),targetString);
		printf("1 %s\n", srcString.c_str());
		srcString.replace(pos+strlen(targetString.c_str()) , strlen(strfind.c_str()) - strlen(targetString.c_str()) ,"");	
		printf("2 %s\n", srcString.c_str());
		pos = srcString.find(strfind.c_str());
	}
	
}
int main(void)
{
	string src;
	string	src0= "/tmp/hdd/volumes/HDD1/BT/01 abc";	
	printf("before src0: %s\n",src0.c_str());
	src0.replace(strlen("/tmp/hdd/volumes/HDD1/BT/01"),1 ,"\\ ");
	printf("after  src0: %s\n",src0.c_str());

	src= "/abc/def<br/>hij/02<br/>hh h";

	string target;
	target="\r\n";
	string strFind ="<br/>";
	printf("before src :%s\n",src.c_str());
	UTIL_String_Replace(src,strFind, target);
	//src.replace("<br/>","\r\n");
	printf("after src :%s\n",src.c_str());


	


	return 0;
}
