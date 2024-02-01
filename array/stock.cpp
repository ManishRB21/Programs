#include<iostream>
using namespace std;
int profit(int ar[], int n){
	int profit =0;
	for(int i=1; i<n;i++){
		if(ar[i]>ar[i-1])
		profit= profit+(ar[i]-ar[i-1]);
		}
	return profit;
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
	cout<<"profit "<<profit(ar,n);
	
}
