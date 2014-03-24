#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#include <vector>

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
struct	JobInfo
{
	int id;	
	char errorMark;char doneStr[5];char haveStr[10];char haveUnit[3];char etaStr[9];double up_tr_speed_K;double down_tr_speed_K;
	char ratioStr[6];char statusString[12];char name[260];
	JobInfo()
	{ 
		 errorMark = 0;
		 memset(doneStr, 0, sizeof(doneStr));memset(haveStr, 0, sizeof(haveStr)); 
		 memset(haveUnit, 0, sizeof(haveUnit));;memset(etaStr, 0, sizeof(etaStr));
		 memset(ratioStr, 0, sizeof(ratioStr));memset(statusString, 0, sizeof(statusString));
		 memset(name, 0, sizeof(name));
	}
};

int main(int argc, char **argv)
{
	FILE *pf;

	if(argc<2)
	{
		printf("sc file\n");
		return -1;
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pf = fopen(argv[1], "r");
	if(pf==NULL)
		exit(-1);
	
	vector<string> vstr;
	vector<JobInfo> vJI;
	
	for(int out_index = 0; (read = getline(&line, &len, pf)) != -1 ;out_index++)
	{		

		vstr.clear();
		splitString(line," ",vstr );
		//std::cout<<"  ";
		int i = 0 ;
		JobInfo ji;
		for(vector<string>::const_iterator  citer = vstr.begin(); citer != vstr.end();i++, citer++)
		{	
			
			
			std::cout<<  *citer <<"  ";
			const char *ci_cstr = (*citer).c_str();
			
			if(0 == i)
			{
				ji.id = atoi(ci_cstr);
				if(strchr( ci_cstr,'*')!= NULL)
					ji.errorMark = '*';			
			}
			else if(1 == i)
				strncpy(ji.doneStr ,ci_cstr, strlen(ci_cstr));
			else if(2 == i)
				strncpy(ji.haveStr ,ci_cstr, strlen(ci_cstr));
			else if(3 == i)
				strncpy(ji.haveUnit , ci_cstr, strlen(ci_cstr));
			else if(4 == i)
				strncpy(ji.etaStr ,ci_cstr, strlen(ci_cstr));
			else if(5 == i)
				ji.up_tr_speed_K = atof(ci_cstr);				
			else if(6 == i)
				ji.down_tr_speed_K = atof(ci_cstr);	
			else if(7 == i)
				strncpy(ji.ratioStr , ci_cstr, strlen(ci_cstr));
			else if(8 == i)
				strncpy(ji.statusString , ci_cstr, strlen(ci_cstr));
			else if(9 == i)
				strncpy(ji.name ,ci_cstr, strlen(ci_cstr));
		}
		if(out_index == 0  )
			continue;
		
		vJI.push_back(ji);				
		std::cout<< std::endl;
	}
	
 	vJI.pop_back();
	
	printf("==================\n");
	for(vector<JobInfo>::const_iterator  citer= vJI.begin(); citer!=vJI.end();  citer++)
	{
		//printf("%-4d %c  %4s  %6.1f  %-11s  %s \n", citer->id, citer->errorMark, citer->doneStr, citer->down_tr_speed_K, citer->statusString, citer->name);
		printf("id:%-4d  doneStr：%4s  down_tr_speed_K：%6.1f  statusString：%-11s  name：%s \n", citer->id, citer->doneStr, citer->down_tr_speed_K, citer->statusString, citer->name);
	}
	free(line);
	fclose(pf);
}
