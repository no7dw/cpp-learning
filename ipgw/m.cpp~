#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;


//splitString函数的参数说明：  
//返回值是分割后字符串数组大小  
//strSrc 原始字符串  
//strDelims 自定义的分割字符串的分割数组  
//strDest 分割后的字符串数组，引用传递  
int  splitString(const string & strSrc, const std::string& strDelims, vector<string>& strDest)  
{  
        typedef std::string::size_type ST;  
        string delims = strDelims;  
        std::string STR;  
        if(delims.empty()) 
			delims = "\n\r";  
      
        ST pos=0, LEN = strSrc.size();  
        while(pos < LEN )
		{
            STR="";   
            while( (delims.find(strSrc[pos]) != std::string::npos) && (pos < LEN) ) 
				++pos;  
            if(pos==LEN) 
				return strDest.size();  
            while( (delims.find(strSrc[pos]) == std::string::npos) && (pos < LEN) ) 
				STR += strSrc[pos++];  
            //std::cout << "[" << STR << "]";  
            if( ! STR.empty() ) 
				strDest.push_back(STR);
        }
        return strDest.size();  
} 

int get_gateway(const char * szFile, char *gateway)
{
	FILE *pf;	
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pf = fopen( szFile, "r");
	if( pf == NULL )
		return -1;
	
	char lastline[200]={0};memset(lastline, 0, sizeof(lastline));
	vector<string> vstr;
	
	while((read = getline(&line, &len, pf)) != -1)//first line
	{	 
		strncpy(lastline, line, strlen(line));
	}
	if(strlen(lastline) > 0)
	{
// 		printf("last line : %s",lastline);
		splitString(lastline," ",vstr  );
// 		printf("%s",vstr[1].c_str());
	}
	fclose(pf);
	strncpy(gateway, vstr[1].c_str(), strlen(vstr[1].c_str()));
	return 0;
}
int get_ip_mask(const char * szFile, char *ip, char *mask)
{
	FILE *pf;	
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pf = fopen( szFile, "r");
	if( pf == NULL )
		return -1;
	
	char lastline[200]={0};memset(lastline, 0, sizeof(lastline));
	vector<string> vstr;
	int linecount = 1;
	while((read = getline(&line, &len, pf)) != -1)//first line
	{	 
		if(2 == linecount)
		{
			strncpy(lastline, line, strlen(line));//read second line
			break;
		}		
		linecount++;
	}
	if(strlen(lastline) > 0)
	{
// 		printf("last line : %s",lastline);
		splitString(lastline," ",vstr  );
// 		printf("%s",vstr[1].c_str());
// 		printf( "%s ",vstr[3].c_str());
	}
	
	string strip= vstr[1].substr(strlen("addr:") ,strlen(vstr[1].c_str()) -strlen("addr:") ) ;
	string strmask= vstr[3].substr( strlen("Mask:"),strlen(vstr[3].c_str()) -strlen("Mask:")-1  ) ;
	
// 	printf("\nstrip= %s ",strip.c_str());
// 	printf( "\nstrmask= %s ",strmask.c_str());
		
	strncpy(ip,strip.c_str(), strlen(strip.c_str()));
	strncpy(mask,strmask.c_str(), strlen(strmask.c_str()));
	
	fclose(pf);
	return 0;
}
int main(void )
{	
	char ip[16] = {0}; char mask[16] = {0};char gateway[15] ={0};
	memset(ip, 0, sizeof(ip));memset(mask, 0, sizeof(mask));memset(gateway, 0, sizeof(gateway));
	get_ip_mask("/tmp/hdd/root/ip", ip,  mask);
	get_gateway("/tmp/hdd/root/gw", gateway);
	printf(" %s  %s %s",ip, mask, gateway);	
	char strcmd[200] = {0};memset(strcmd, 0, sizeof(strcmd));
	sprintf(strcmd,"ifconfig eth0 %s netmask %s",ip, mask);	
	system(strcmd);
	sprintf(strcmd, "route add default gw %s", gateway);
	system(strcmd);
}
