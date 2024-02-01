#include<iostream>
using namespace std;

int selection(int ar[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(ar[j]<ar[i]){
				swap(ar[j],ar[i]);
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
	selection(ar,n);
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
}
