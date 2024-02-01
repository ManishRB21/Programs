#include<iostream>
using namespace std;
int movezero(int ar[], int n){
	int count =0;
	for(int i=0; i<n; i++){
		if(ar[i]!=0){
			swap(ar[i],ar[count]);
			count++;
		}
	}
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
	movezero(ar,n);
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
}

