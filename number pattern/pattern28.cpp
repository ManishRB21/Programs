#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int temp=1;
	for(int i=1;i<=n/2+1;i++){
		for(int j=1;j<=i;j++){
			cout<<temp*j<<" ";
		}
		temp++;
		cout<<endl;
	}
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=n/2+1-i;j++){
			cout<<temp*j<<" ";
		}
		temp++;
		cout<<endl;
	}
}
