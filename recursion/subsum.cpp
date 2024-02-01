#include<iostream>
using namespace std;
int subsum(int arr[], int n, int sum){
	if(sum==0){
		return 1;
	}
	if(n==0){
		return 0;
	}
	return subsum(arr,n-1,sum)+subsum(arr,n-1,sum-arr[n-1]);
}
int main(){
	int k;
	int arr[]={3,34,4,12,5,2};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<"enter k";
	cin>>k;
	cout<<subsum(arr,n,k);
	return 0;
}
