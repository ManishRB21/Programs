#include<iostream>
using namespace std;
int windowslide(int ar[], int n, int k){
	int cur, maxsum=0;
	for(int i=0; i<k;i++){
		cur= cur+ar[i];
	}
	for(int i=k; i<n;i++){
		cur= cur+ar[i]-ar[i-k];
		maxsum= max(cur, maxsum);
	}
	return maxsum;
}

int main(){
	int ar[100];
	int n=6,k;
	cout<<"enter array ";
	for(int i=0; i<n; i++){
		cin>>ar[i];
	}
	for(int i=0; i<n; i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	cin>>k;
	cout<<"sum ";
	cout<<windowslide(ar,n,k);
}
	

