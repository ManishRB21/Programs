#include<iostream>
using namespace std;
int maxEO(int ar[], int n){
	int res=1, cur=1;
	for(int i=1;i<n;i++){
		if((ar[i]%2==0 && ar[i-1]%2!=0) || (ar[i]%2!=0 && ar[i-1]%2==0)){
			cur++;
			res = max(res,cur);
		}
		else
		cur=1;
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
	cout<<"max even odd length "<<maxEO(ar,n);
}
	

