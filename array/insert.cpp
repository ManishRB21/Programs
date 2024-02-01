#include<iostream>
using namespace std;
int insert(int ar[], int x, int n, int pos){
	int idx = pos-1;
	for(int i=n-1; i>=idx; i--){
		ar[i+1]=ar[i];
	}
	ar[idx]=x;
}
int main(){
	int ar[100];
	int n=5,x,pos;
	cout<<"enter array ";
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	cin>>x;
	cin>>pos;
	insert(ar,x,n,pos);
	for(int i=0;i<n+1;i++){
		cout<<ar[i]<<" ";
	}
	return 0;
}

