#include <iostream>
using namespace std;

void function(int &refval){
	refval=100;
}

int main()
{
	int x=200;
	function(x);
	cout<<"x = "<<x<<endl;
	return 1;

}
