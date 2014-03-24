#ifndef _CALLBACK_
#define _CALLBACK_

/*以C方式编译*/
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

/*待交换的数据结构*/
typedef struct NODE
{
	int n;
	char c;
	float f;
	double d;
	char* pc;	
}Node;


/*定义函数指针*/
typedef void (*MY_SWAP)(Node*,Node*);


/* 回调函数，交换*a和*b */
void swap_my(Node* a, Node* b) ;

/*通过函数指针调用回调函数*/
void fun(Node* a, Node* b, MY_SWAP swap1);

#ifdef __cplusplus
}
#endif


#endif