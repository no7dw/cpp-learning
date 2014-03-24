#include <stdio.h>
#include "type.h"
void InsertSort(SqList *L)
{
    int i,j,com;
    for( i= 1; i< L->length; i++)
    {
        if(L->data[i]<L->data[i-1])
        {
            com = L->data[i];
            for( j= i; com < L->data[j-1] ; j--)
            {
                L->data[j]=L->data[j-1];
            }
            L->data[j]= com;
        }
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
    
    l.data[0] = 9;
    l.data[1] = 1;
    l.data[2] = 5;
    l.data[3] = 8;
    l.data[4] = 3;
    l.data[5] = 7;
    l.data[6] = 4;
    l.data[7] = 6;
    l.data[8] = 2;
    
    l.length = 9;
    printContent(&l);
    printf("\n");
    InsertSort(&l);
    printContent(&l);
    printf("\n");

    return 0;
}
