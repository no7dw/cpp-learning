#include <stdio.h>
#define RATE 16000
#define SIZE 16

int main(void)
{
	double m_dtime = 3.2847;
	int size = ((m_dtime-0.7) * RATE * SIZE/8);  
	printf("size = %d\n", size);
	return 0;
}
