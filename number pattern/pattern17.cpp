#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int s=1;s<=i;s++){
			cout<<" ";
		}
		for(int j=i;j<=n;j++){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	for(int i=n;i>=1;i--){
		for(int s=i;s>=1;s--){
			cout<<" ";
		}
		for(int j=i;j<=n;j++){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	
}
