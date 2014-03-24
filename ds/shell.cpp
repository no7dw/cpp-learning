#include <stdio.h>
#include "type.h"
void ShellSort(SqList *L)
{
    
   int increase_step = 2; 
   //div List into servral column , and each column use insert sort
    for(int column = L->length/increase_step; column >0; column=column/increase_step)
    {
    		//insert sort of each column
	    for( int line = column; line < L->length; line++)
	    {
		    int com = L->data[line];
		    int j= line - column;
		    //in a step of column_num
		    for( ; com < L->data[j] && j>=0 ; j-=column)
		    {
			L->data[j+column]=L->data[j];
		    }
		    L->data[j+column] = com;
	    }
	    //for clear watch a List , output the List in column 
	    for(int i = 0; i< L->length; i++)
	    {
			if(0== i%column)
				printf("\n");
			printf("%d ", L->data[i]);
			
	    }
	printf("\n\n");

    }
}
void printContent(SqList *L)
{
    for(int i = 0; i< L->length; i++)
    {
        printf("%d \t",L->data[i] );
    }
}
int main(void)
{
    SqList l ;
   
   l.data={17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
   l.length = 17;
    printContent(&l);
    printf("\n");
    ShellSort(&l);
    printContent(&l);
    printf("\n");

    return 0;
}
