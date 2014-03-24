#include <iostream>
#include <stdio.h>
using namespace std;
int  main()
{
    /// int型数据的最大值
    int intMax = int(((unsigned int)(~0)) >> 1);
    cout << intMax << endl;

 

    /// int型数据的最小值
    int intMin = (unsigned int)(~1)>>1;
    intMin = ~intMin;
    cout << intMin << endl;

    return 0;
}
