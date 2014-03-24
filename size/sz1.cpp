#include <stdio.h>
union a {
	
	 int a_int1;
	 
	  double a_double;
	  
	   int a_int2;
	   
};

typedef struct

{
	
	 a a1;
	 
	  char y;
	  
} b;

class c

{
	
	 double c_double;
	 
	  b b1;
	  
	   a a2;
	   
};
int main(void)
{
	printf("sizeof(a) = %d \n" ,sizeof(a) );
	printf("sizeof(b) = %d \n" ,sizeof(b) );
	printf("sizeof(c) = %d \n" ,sizeof(c) );
}
