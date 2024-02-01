#include<iostream>
using namespace std;
int large(int ar[], int n){
	int res=0;
	for(int i=0;i<n;i++){  
		if(ar[i]>ar[res])
		res=i;
	}
	return res;
}
int main(){
	int ar[100];
	int n=5;
	cout<<"enter array ";
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	cout<<"index number "<<large(ar,n);
	return 0;
	
}
