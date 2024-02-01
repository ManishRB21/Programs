#include<iostream>
using namespace std;
int subarraysum(int ar[], int n){
	int res= ar[0];
	int maxend=ar[0];
	for(int i=1 ; i<n;i++){
		maxend= max(ar[i], maxend+ar[i]);
		res= max(res, maxend);
	}
	return res;
}

int main(){
	int ar[100];
	int n=7;
	cout<<"enter array ";
	for(int i=0; i<n; i++){
		cin>>ar[i];
	}
	for(int i=0; i<n; i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	cout<<"max sub array sum "<<subarraysum(ar,n);
}

