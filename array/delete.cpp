#include<iostream>
using namespace std;
int main(){
	int ar[100],n=5,pos;
	cout<<"enter array ";
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	cin>>pos;
	for(int i=pos-1;i<n;i++){
		ar[i]=ar[i+1];
	}
	cout<<"enter array ";
	for(int i=0;i<n-1;i++){
		cout<<ar[i]<<" ";
	}
}
