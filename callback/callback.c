#include "callback.h"
#include <unistd.h>
/* 回调函数，交换*a和*b */
void swap_my(Node* a, Node* b)  
{
	printf("in swap_my\n");
	/*定义临时变量*/
	int tmp_n;
	char tmp_c;
	float tmp_f;
	double tmp_d;
	char* p_tmp;


	/*交换int型数据*/
	tmp_n = a->n;
	a->n = b->n;
	b->n = tmp_n;

	/*交换char型数据*/
	tmp_c = a->c;
	a->c = b->c;
	b->c = tmp_c;

	/*交换float型数据*/
	tmp_f = a->f;
	a->f = b->f;
	b->f = tmp_f;

	/*交换double型数据*/
	tmp_d = a->d;
	a->d = b->d;
	b->d = tmp_d;

	/*交换char*型数据*/
	p_tmp = a->pc;
	a->pc = b->pc;
	b->pc = p_tmp;
	
	sleep(3);
	printf("out swap_my\n");
}


/*通过函数指针调用回调函数*/
void fun(Node* a, Node* b, MY_SWAP swap1)
{
	swap1(a,b);
}

