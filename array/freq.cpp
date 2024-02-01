#include<iostream>
using namespace std;
int freq(int ar[], int n){
	int freq=1, i=1;
	while(i<n){
		while(i<n && ar[i]==ar[i-1]){
			freq++;
			i++;
		}
		cout<<ar[i-1]<<" "<<freq<<endl;
		i++;
		freq=1;
	}
	if(n==1 || ar[n-1]!=ar[n-2])
	cout<<ar[n-1]<<" "<<1<<endl;
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
	freq(ar,n);
	
}
