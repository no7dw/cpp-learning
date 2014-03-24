#ifndef _CALLBACK_
#define _CALLBACK_

/*��C��ʽ����*/
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

/*�����������ݽṹ*/
typedef struct NODE
{
	int n;
	char c;
	float f;
	double d;
	char* pc;	
}Node;


/*���庯��ָ��*/
typedef void (*MY_SWAP)(Node*,Node*);


/* �ص�����������*a��*b */
void swap_my(Node* a, Node* b) ;

/*ͨ������ָ����ûص�����*/
void fun(Node* a, Node* b, MY_SWAP swap1);

#ifdef __cplusplus
}
#endif


#endif