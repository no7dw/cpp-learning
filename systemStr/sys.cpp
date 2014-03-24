#include <stdio.h>
#include <string.h>

int main(void)
{
    int grade = 12;
    const char *Name = "lesson1";
    
    char strcmd[300] = {0};
    char SrcDirPath[100] = {0};
    char TargetDirPath[100] = {0};

    sprintf(SrcDirPath ,  "/tmp/hdd/volumes/HDD1/BT/%s" , Name);
    sprintf(TargetDirPath , "LGSystem/STXD/第%d阶/",grade );
    
    char strcp[4] = "cp ";	
    char strcp2[5] = " -rf";

    memcpy(strcmd , strcp, strlen(strcp) );
    memcpy(strcmd + strlen(strcp), SrcDirPath, strlen(SrcDirPath) );
    memcpy(strcmd + strlen(strcp) + strlen(SrcDirPath), " ", strlen(" ") );
    memcpy(strcmd + strlen(strcp) + strlen(SrcDirPath) + strlen(" ") , TargetDirPath, strlen(TargetDirPath) );
    memcpy(strcmd + strlen(strcp) + strlen(SrcDirPath) + strlen(TargetDirPath), strcp2 , strlen(strcp2 ) );

    printf(strcmd);
    printf("\n");
//    system(strcmd);
}
