#include <stdio.h> 
//输出内容
void print_content(int *a, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
int Partition(int *a, int low, int high)
{
	printf("pivotkey:%d a[%d ~ %d] : [%d - %d] \n", a[low], low,high-1 , a[low], a[high-1]);    
    int pivotkey = a[low];
    //注意左右分别对应传入的low high
    while(low<high)
    {
        while(low<high && a[high]>=pivotkey)//中枢要比右边的小
            --high;
        a[low]=a[high];//发现一个比中枢小的，移到左边

        while(low<high && a[low]<=pivotkey)//中枢要比左边的大
            ++low;
        a[high]=a[low];//发现一个比中枢大的，移到右边
    }
    a[low]=pivotkey;//现在high = low,将中枢移到中间

    return low;
}

void QSort(int *a, int low, int high)
{
    if(low<high)
    {
        int pivotloc = Partition(a, low, high);
	print_content(a,8);
        QSort(a, low, pivotloc-1);
        QSort(a, pivotloc+1, high);

    }
}
int main(void)
{
//    int a[]={0,7,8,9,3,4,5,1,2,6,11,10,13,12};
    int a[]={49,38,65,97,76,13,27,49};
    print_content(a,sizeof(a)/sizeof(a[0]));
    QSort(a,0,sizeof(a)/sizeof(a[0]));//40/4
    print_content(a,sizeof(a)/sizeof(a[0]));
    return 0;
}
