#include<iostream>
using namespace std;

int func(int ar[], int n)
{
	int res=0;
	for(int i=0; i<n; i++){
		res= res^ar[i];
	}
	cout<<res;
}
// driver code
int main()
	{
		int ar[]={1,2,3,4,6,5,5,4,4,6,2,3,4};
		int n= sizeof(ar)/sizeof(ar[0]);
		func(ar,n);
}

