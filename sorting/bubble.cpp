#include<iostream>
using namespace std;

int bubble(int ar[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(ar[j]>ar[j+1]){
				swap(ar[j],ar[j+1]);
			}
		}
	}
}

int main(){
	int n=5;
	int ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	bubble(ar,n);
	for(int i=n-1;i>=0;i--){
		cout<<ar[i]<<" ";
	}
}
