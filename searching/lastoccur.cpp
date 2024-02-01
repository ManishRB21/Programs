#include<iostream>
using namespace std;
int lastoccur(int ar[], int n, int x){
	for(int i=n-1; i>=0;i--){
		if(ar[i]==x)
		return i;
	}
}

int main(){
	int ar[100];
	int n=5,x;
	cout<<"enter array"<<endl;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	cin>>x;
	cout<<"last occurence "<<lastoccur(ar,n,x);
}
