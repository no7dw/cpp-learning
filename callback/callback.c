#include "callback.h"
#include <unistd.h>
/* �ص�����������*a��*b */
void swap_my(Node* a, Node* b)  
{
	printf("in swap_my\n");
	/*������ʱ����*/
	int tmp_n;
	char tmp_c;
	float tmp_f;
	double tmp_d;
	char* p_tmp;


	/*����int������*/
	tmp_n = a->n;
	a->n = b->n;
	b->n = tmp_n;

	/*����char������*/
	tmp_c = a->c;
	a->c = b->c;
	b->c = tmp_c;

	/*����float������*/
	tmp_f = a->f;
	a->f = b->f;
	b->f = tmp_f;

	/*����double������*/
	tmp_d = a->d;
	a->d = b->d;
	b->d = tmp_d;

	/*����char*������*/
	p_tmp = a->pc;
	a->pc = b->pc;
	b->pc = p_tmp;
	
	sleep(3);
	printf("out swap_my\n");
}


/*ͨ������ָ����ûص�����*/
void fun(Node* a, Node* b, MY_SWAP swap1)
{
	swap1(a,b);
}

