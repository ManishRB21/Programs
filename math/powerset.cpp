#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
void powerset(char *str, int n){
	int powsize= pow(2,n);
	for(int counter=0; counter<powsize; counter++){
		for(int j=0; j<n; j++){
			if(counter & (1<<j))
			cout<<str[j];
		}
		cout<<"\n";
	}
}
int main()
	{
		char str[]={'a','b','c'};
		powerset(str, 3);
	}
