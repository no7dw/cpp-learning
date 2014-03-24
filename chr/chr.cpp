#include <stdio.h>
#include <string.h>
int main(void)
{
	char *te="01 的发";
	char *t2=strchr(te, 0x20);
	printf("%s\n",++t2);

	char *m_Course = "01 随便的课程名称";
	char *pCourseName = m_Course;

	char ctmp[255]={0};

pCourseName = strchr(m_Course, 0x20);
pCourseName = pCourseName + 1;
memset(ctmp, 0, 255);
sprintf(ctmp,"【%s】看图学单词--单人跟读训练",pCourseName);
printf("%s\n",ctmp);
}
