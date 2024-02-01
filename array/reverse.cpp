#include<iostream>
using namespace std;
int reverse(int ar[],int n){
	int low=0, high= n-1;
	while(low<high){
		int temp=ar[low];
		ar[low]=ar[high];
		ar[high]=temp;
		low++;
		high--;
	}
	
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
	reverse(ar,n);
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
}

