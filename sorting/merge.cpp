#include<iostream>
using namespace std;

void merge(int a[], int b[], int m, int n){
	int i=0, j=0;
	while(i<m && j<n){
		if(a[i]<=b[j]){
			cout<<a[i]<<" ";
			i++;
		}
		else{
			cout<<b[j]<<" ";
			j++;
		}
	}
		while(i<m){
			cout<<a[i]<<" ";
			i++;
		}
		while(j<n){
			cout<<b[j]<<" ";
			j++;
		}
	
}

int main(){
	int m=3,n=3;
	int a[m],b[n];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	merge(a,b,m,n);
	
	
}
