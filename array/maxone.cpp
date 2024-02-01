#include<iostream>
using namespace std;
int maxone(int ar[], int n){
	int res=0;
	int cur =0;
	for(int i=0;i<n;i++){
		if(ar[i]==0){
			cur=0;
		}
		else
		cur++;
		res=max(res,cur);
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
	cout<<"consecutive ones "<<maxone(ar,n);
	
}
