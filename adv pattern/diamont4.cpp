#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int s=n;s>i;s--){
			cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		for(int s=1;s<=2;s++){
			cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=n;i>=1;i--){
		for(int s=n;s>i;s--){
			cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		for(int s=1;s<=2;s++){
			cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
	}
}
