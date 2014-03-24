#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int array[], int low, int mid, int high)
{
        int i, k;
        int *temp = (int *) malloc((high-low+1) * sizeof(int)); //申请空间，使其大小为两个
//已经排序序列之和，该空间用来存放合并后的序列
        int begin1 = low;
        int end1 = mid;
        int begin2 = mid + 1;
        int end2 = high;
 
        for (k = 0; begin1 <= end1 && begin2 <= end2; ++k)  //比较两个指针所指向的元素，
//选择相对小的元素放入到合并空间，并移动指针到下一位置
        { 
            if(array[begin1]<=array[begin2])
             {
              temp[k] = array[begin1++];
             }
            else
            {   
             temp[k] = array[begin2++];
            }
        }
        if(begin1 <= end1) //若第一个序列有剩余，直接拷贝出来粘到合并序列尾
        {
          memcpy(temp+k, array+begin1, (end1-begin1+1)*sizeof(int));
        }
        if(begin2 <= end2) //若第二个序列有剩余，直接拷贝出来粘到合并序列尾
        {
          memcpy(temp+k, array+begin2, (end2-begin2+1)*sizeof(int));
        }
        memcpy(array+low, temp, (high-low+1)*sizeof(int));//将排序好的序列拷贝回数组中
        free(temp);
}
void merge_sort(int array[], unsigned int first, unsigned int last)
{
        int mid = 0;
        if(first<last)
        {
                /*mid = (first+last)/2;*/ /*注意防止溢出*/
                /*mid = first/2 + last/2;*/
                mid = (first & last) + ((first ^ last) >> 1);
                merge_sort(array, first, mid);
                merge_sort(array, mid+1,last);
                merge(array,first,mid,last);
        }
}

void print_content(int *a, int size)
{
		for(int i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
}
int main(void)
{

		int a[]={10,17,18,19,13,14,15,11,12,16,21,20,23,22};
		merge_sort(a,0,sizeof(a)/sizeof(a[0]));
		print_content(a,sizeof(a)/sizeof(a[0]));

		return 0;
}

