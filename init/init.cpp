#include <stdio.h>
int main(void)
{
//char buff[10] ={ 'a' };
char buff[10] ={ NULL };
int i;
for( i =0; i<10; i++)
{
	if(buff[i]==NULL )
		printf(" is NULL\n");
	else	
		printf("not null buff[%d] = %c\n", i , buff[i]);
}

bool b[10] ={false};
for( i =0; i<10; i++)
{
	if(b[i]==false )
		printf(" is false\n");
	else	
		printf("not false b[%d] = %d\n", i , b[i]);
}

return 0;

}
