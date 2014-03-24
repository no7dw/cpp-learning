#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char a[50];
	memset(a,0,sizeof(a));
	cin.getline(a,50,'\n');
	int i=0,j;
	j=strlen(a)-1;
	char t;
	for(;i<strlen(a)/2;i++,j--)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;	
	}
	cout << a<< endl;
}
