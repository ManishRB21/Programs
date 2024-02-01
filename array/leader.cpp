#include<iostream>
using namespace std;
void leader(int ar[], int n){
	int cur= ar[n-1];
	cout<<cur<<" ";
	for(int i=n-2; i>=0;i--){
		if(cur<ar[i]){
			cur=ar[i];
			cout<<cur<<" ";
		}
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
	leader(ar,n);
	return 0;
}
