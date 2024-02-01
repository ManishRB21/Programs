#include<iostream>
using namespace std;
int duplicate(int ar[], int n){
	int res=1;
	for(int i=1; i<n;i++){
		if(ar[i]!=ar[res-1]){
			ar[res]=ar[i];
			res++;
		}
	}
	return res;
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
	cout<<"size after removing duplicate "<<duplicate(ar,n);
	
}

