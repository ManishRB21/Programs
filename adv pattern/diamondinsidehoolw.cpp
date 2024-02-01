#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		for(int s=n;s>i;s--){
			cout<<"*";
		}
		for(int j=1;j<=i;j++){
			cout<<" ";
		}
			for(int j=2;j<=i;j++){
			cout<<" ";
		}
		for(int s=n;s>i;s--){
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i=n-1;i>=1;i--){
		for(int s=n;s>i;s--){
			cout<<"*";
		}
		for(int j=1;j<=i;j++){
			cout<<" ";
		}
			for(int j=2;j<=i;j++){
			cout<<" ";
		}
		for(int s=n;s>i;s--){
			cout<<"*";
		}
		cout<<endl;
	}
}
