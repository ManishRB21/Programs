#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int num;
	cin>>num;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<num;
		}
		num++;
		cout<<endl;
	}
	num--;
	for(int i=n-1;i>=1;i--){
		num--;
		for(int j=1;j<=i;j++){
			cout<<num;
		}
		
		cout<<endl;
	}
}
