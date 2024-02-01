#include<iostream>
using namespace std;

int func(int ar[], int n)
{
	int x1 =ar[0];
	int x2= 1;
	for(int i=1; i<n; i++){
		x1= x1^ar[i];
	}
	for(int i=2; i<=n+1; i++){
		x2= x2^i;
	}
	int m= (x1^x2);
	cout<<m;
}
// driver code
int main()
	{
		int ar[]={1,2,3,4,6};
		int n= sizeof(ar)/sizeof(ar[0]);
		func(ar,n);
}

