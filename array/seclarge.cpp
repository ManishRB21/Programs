#include<iostream>
using namespace std;
int seclargest(int ar[], int n){
	int res= -1, largest=0;
	for(int i=1; i<n; i++){
		if(ar[i]>ar[largest]){
			res=largest;
			largest=i;
		}
		else{
			if(ar[i]<ar[largest]){
				if(res==-1 || ar[i]>ar[res])
				res=i;
			}
		}
	}
	return ar[res];
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
	cout<<"index number "<<seclargest(ar,n);
	return 0;
	
}
