#include<iostream>
using namespace std;
/*int sort(int ar[], int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(ar[i]<ar[j])
			return 1;
		}
	}
	return 0;
}
*/
bool sort(int ar[], int n){
	for(int i=1; i<n; i++){
			if(ar[i-1]<ar[i])
			return true;
		}
	return false;
	}
	
int main(){
		int ar[100];
	int n=5;
	cout<<"enter array ";
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	if(sort(ar,n))
	cout<<"sorted";
	else
	cout<<"unsorted";
	return 0;
	
}
