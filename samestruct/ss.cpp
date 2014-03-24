#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const short ID_SIZE = 48+1; //由于软件升级，该为存取软件升级包的Hash
const short  NAME_SIZE = 256;
const short  PATH_SIZE = 100+1;
const short  HASH_SIZE = 48+1;
const short  MAX_PATH  = 255;
struct CourseInfo{
	
	char ID[ID_SIZE];
	char Name[NAME_SIZE];
	char Path[PATH_SIZE];
	char Hash[HASH_SIZE];
	int Level;//1-12阶段
	int Grade;//优先级别
	int SendbySM;//那个模式的
	int Status;//状态 0 UNBOOK 1 BOOK 2 DOWNLOADING 3 COMPLETED
	int Last_Percent;
	CourseInfo()
	{
	    memset(ID,0,sizeof(ID));
	    memset(Name,0,sizeof(Name));
	    memset(Path,0,sizeof(Path));
	    memset(Hash,0,sizeof(Hash));	    
	    Level = 0;
	    Grade = 0;
	    SendbySM = 0;
	    Status = 1;
	    Last_Percent = 0;
	}
};

class resource
{
/*
public:
	resource();
	~resource();
*/
public:
	CourseInfo CI;
	virtual void book();

};
void resource::book()
{
	printf("book resource\n");
}



class update:public resource
{
/*
public:
	update();
	~update();
*/
public:
	CourseInfo CI;
	void book();

};

void update::book()
{
	printf("book update\n");
}


class server{
public:
	void start(resource *pr1);
};


void server::start(resource *pr1)
{
	
	pr1->book();
}

int main( void )
{
	resource *pr1 = new resource();
	resource *pu1 = new update();
	
	server s1;

	s1.start(pr1);

	printf("\n************\n");

	s1.start(pu1);
}
