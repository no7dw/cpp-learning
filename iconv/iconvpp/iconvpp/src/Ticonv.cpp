#include "../include/iconvpp/iconvpp.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	Iconvpp::Encoding IE1;
string src = "04 鏁板瓧1鍒";
	//std::string from = "utf-8";
	//std::string to = "gbk";
	//printf("%s\n",	IE1.convert( src, from ,to ) );
	printf("%s\n",	IE1.utf8_to_gbk( src ) );
}
