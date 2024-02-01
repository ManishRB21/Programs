#include<iostream>
using namespace std;
int subarray(int ar[], int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++){
				cout<<ar[k]<<" ";
			
			}
		cout<<endl;
		}
	}
}


int main(){
	int ar[]={1,2,3};
	int n= sizeof(ar)/sizeof(ar[0]);
	subarray(ar,n);
	return 0;
}
