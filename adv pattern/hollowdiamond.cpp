#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int s=i;s<n;s++){
			cout<<" ";
		}
		if(i==1){
			for(int j=1;j<=i;j++){
				cout<<"* ";
			}
		}
		else{
			cout<<"*";
			for(int j=1;j<=2*i-3;j++){
				cout<<" ";
			}
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i=n-1;i>=1;i--){
		for(int s=i;s<n;s++){
			cout<<" ";
		}
		if(i==1){
			for(int j=1;j<=i;j++){
				cout<<"* ";
			}
		}
		else{
			cout<<"*";
			for(int j=1;j<=2*i-3;j++){
				cout<<" ";
			}
			cout<<"*";
		}
		cout<<endl;
	}
}

