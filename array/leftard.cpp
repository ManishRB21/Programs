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

int leftard(int ar[], int n,int d){
	for(int i=0; i<d; i++){
		{
			leftar(ar, n);
		}
	}
}
int main(){
	int ar[100];
	int n=5,d;
	cout<<"enter array ";
	for(int i=0; i<n; i++){
		cin>>ar[i];
	}
	for(int i=0; i<n; i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	cin>>d;
	leftard(ar,n,d);
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
}

