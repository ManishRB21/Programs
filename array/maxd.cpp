#include<iostream>
using namespace std;
int maxd(int ar[], int n){
	int res=ar[1]-ar[0];
	for(int i=0; i<n-1;i++){
		for(int j=i+1; j<n;j++){
			res = max(res, ar[j]-ar[i]);
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
	cout<<"diff "<<maxd(ar,n);
	
}
