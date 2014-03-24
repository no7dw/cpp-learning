#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
using namespace std;

int GetRandomI(int iTotalNum, int iGetCount,vector<int> *retVi )
{
	int *aTest =  new int[iTotalNum];
	for(int nCount = 0; nCount < iTotalNum; nCount ++)
	{
		aTest[nCount] = nCount;
	}
	int nPos, nTemp;

	srand((unsigned)time(NULL));

	for(int nCount = 0; nCount < iTotalNum ; nCount ++)
	{
		nPos = rand()%10;
		nTemp = aTest[nPos];
		aTest[nPos] = aTest[nCount];
		aTest[nCount] = nTemp;

	//	cout << nCount<<" "<< aTest[nCount]<< endl;

	}
	for(int index = 0; index <iGetCount && index <iTotalNum; index++)
	{
		retVi->push_back(aTest[index]);
	}
	return 0;
}

int main()
{
for(int istart = 0;istart <100; istart++)
{
	vector<int> iretVi;
	GetRandomI(22+istart, 4, &iretVi);
	for(int index = 0; index <iretVi.size() ; index++)
	{
		printf("%d \t", iretVi[index] );
	}
	printf("\n");
	iretVi.clear();
}
	return 0;
}

