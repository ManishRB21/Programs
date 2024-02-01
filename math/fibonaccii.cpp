//Fibonacci Series using Recursion
#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
	if (n==0)
		return 0;
	if (n==1)
		return 1;
	return fib(n-1) + fib(n-2);
}

int main ()
{
	int n;
	cout<<"number";
	cin>>n;
	cout << fib(n);
	return 0;
}

// This code is contributed
// by Akanksha Rai

