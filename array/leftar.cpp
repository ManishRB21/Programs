#include<iostream>
using namespace std;
int leftar(int ar[], int n){
	int temp= ar[0];
	for(int i=1; i<n; i++){
		{
			ar[i-1]=ar[i];
		}
	}
	ar[n-1]=temp;
}
int main(){
	int ar[100];
	int n=5;
	cout<<"enter array ";
	for(int i=0; i<n; i++){
		cin>>ar[i];
	}
	for(int i=0; i<n; i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	leftar(ar,n);
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
}

