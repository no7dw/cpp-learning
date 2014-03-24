#include <stdlib.h>
#include <stdio.h>
//#define MAX_TIME_BUFER 20*16000*16/8
#define MAX_TIME_BUFER 20
#define BUFFER_PER_COUNT 3
//char ***m_pUser_buff;
char m_pUser_buff[3][BUFFER_PER_COUNT][MAX_TIME_BUFER]

void InitUserBuffer(bool RoleA_Join, bool RoleB_Join )
{
	printf ( "--%s-%s--%d----\n",__FILE__ ,__func__, __LINE__);
	int size = MAX_TIME_BUFER ;
	m_pUser_buff = new char**[3];
	//memset(m_pUser_buff, NULL, sizeof(m_pUser_buff)*3);//初始化为 NULL
	//主角必定参与
	//最大原音buffer 20秒
	for(int index = 0;index < BUFFER_PER_COUNT; index++)
	{
		m_pUser_buff[0][index] = new char[size];//最大原音buffer 20秒
	}
	
	printf ( "--%s-%s--%d----\n",__FILE__ ,__func__, __LINE__);
	fflush(stdout);
	if(RoleA_Join)
	{
		printf ( "--%s-%s--%d----\n",__FILE__ ,__func__, __LINE__);
		for(int index = 0;index < BUFFER_PER_COUNT; index++)
		{
			m_pUser_buff[1][index] = new char[size];//最大原音buffer 20秒
		}
	}
	printf ( "--%s-%s--%d----\n",__FILE__ ,__func__, __LINE__);
	fflush(stdout);
	if(RoleB_Join)
	{
		printf ( "--%s-%s--%d----\n",__FILE__ ,__func__, __LINE__);
		for(int index = 0;index < BUFFER_PER_COUNT; index++)
		{
			m_pUser_buff[2][index] = new char[size];//最大原音buffer 20秒
		}
	}
	
}

int main(void)
{

	InitUserBuffer(true,true);
	printf("\nend\n");

}

