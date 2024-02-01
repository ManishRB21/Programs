#include<iostream>
using namespace std;

void insertion(int ar[],int n){
	for(int i=1;i<n; i++){
		int key=ar[i];
		int j=i-1;
		while(j>=0 && ar[j]>key){
			ar[j+1]=ar[j];
			j--;
		}
		ar[j+1]=key;
	}
}

int main(){
	int n=5;
	int ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	insertion(ar,n);
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
}
