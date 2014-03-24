#include <stdio.h>
#include "type.h"
void swap(ElemType *a, ElemType *b)
{
    ElemType tmp = *a;
    *a=*b;
    *b=tmp;
}
void HeapAdjust(SqList *L, int start, int end)
{
	printf("Adjust %d %d \n", start, end);
	int j, temp, i;
	temp = L->data[start];
	i = start;
	//Note:2*start , if start==0, then j==0 . That's why we NEED THE LIST TO START FROM 1, INSTEAD OF 0
	for(j = 2*start; j<=end; j*=2)
	{
		//compare left child [2*start] and right child [2*start+1]
		if(L->data[j]<L->data[j+1] && j<end)
			j++;//right child is larger than left child

		if(temp>=L->data[j])//temp(position [start]) is already the largest
			break;

		L->data[start] = L->data[j];// Note:change

		start = j;//above line changed the heap, we now need to reconstruct
	}
	printf("largest now[%d]:%d <-> [%d]:%d \n",start, L->data[start], temp, i);	
	L->data[start] = temp;
}
void HeapSort(SqList *L)
{
	//construct the list into a heap, starting from nodes with children
	for(int i = (L->length)/2; i>0; i--)
		HeapAdjust(L, i, L->length);
	
	//swap out the largest , and then reconstruct the list into a new heap
	for(int i=L->length; i>1; i--)
	{
		swap(&(L->data[1]), &(L->data[i]));
		HeapAdjust(L, 1, i-1);
	}
}
void printContent(SqList *L)
{
    for(int i = 1; i<= L->length; i++)
    {
        printf("%d \t",L->data[i] );
    }
}
int main(void)
{
    SqList l ;
    l.data={-1,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    l.length = 16;

    printContent(&l);
    printf("\n");
    HeapSort(&l);
    printContent(&l);
    printf("\n");

    return 0;
}
