#include<iostream>
using namespace std;
int trap(int ar[],int n){
	int res=0;
	int lmax[n],rmax[n];
	lmax[0]=ar[0];
	for(int i=1;i<n;i++){
		lmax[i]=max(ar[i],lmax[i-1]);
		}
	rmax[n-1]=ar[n-1];
	for(int i=n-2;i>=0;i--){
		rmax[i]=max(ar[i],rmax[i+1]);
		}
	for(int i=1;i<n-1;i++){
		res= res+ (min(lmax[i],rmax[i])-ar[i]);
		}
	return res;		
}

int main(){
	int ar[100];
	int n=9;
	cout<<"enter array ";
	for(int i=0; i<n; i++){
		cin>>ar[i];
	}
	for(int i=0; i<n; i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	cout<<"trapped rain "<<trap(ar,n)<<" units";
	
}
