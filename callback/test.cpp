#include <stdio.h>
#include "callback.h"
#include <unistd.h>

int main(void)
{
	Node A;
	Node B;

	/*定义A中各元素的值*/
	A.n = 100;
	A.c = 'a';
	A.f = 32.12134;
	A.d = 100.22323;
	A.pc = "hello";
	
	/*定义B中各元素的值*/
	B.n = 200;
	B.c = 'b';
	B.f = 23.12134;
	B.d = 200.22323;
	B.pc = "world";



	/*输出A、B中各元素的值*/
	printf(" A.n = %d, A.c = %c, A.f = %f, A.d = %lf, A.pc = %s \n",
A.n, A.c, A.f, A.d, A.pc);
	printf(" B.n = %d, B.c = %c, B.f = %f, B.d = %lf, B.pc = %s \n",
B.n, B.c, B.f, B.d, B.pc);

	printf("\n-----AFTER SWAP-----\n\n");
	
	fun(&A,&B,swap_my);  /*测调用回调函数*/
	printf("2222 sleep after fun\n");
	sleep(2);
	printf("333 wake up after sleep\n");

	/*输出A、B中各元素的值*/
	printf(" A.n = %d, A.c = %c, A.f = %f, A.d = %lf, A.pc = %s \n",
A.n, A.c, A.f, A.d, A.pc);
	printf(" B.n = %d, B.c = %c, B.f = %f, B.d = %lf, B.pc = %s \n",
B.n, B.c, B.f, B.d, B.pc);



	return 1;
}
