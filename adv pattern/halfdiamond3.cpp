#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int num=1;
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=1;j<=i;j++){
			cout<<num++;
			if(k<i){
			cout<<"*";
			k++;
		}
		}
		cout<<endl;
	}
	num=num-n;
	for(int i=n;i>=1;i--){
		int k=1;
		for(int j=1;j<=i;j++){
			cout<<num++;
			if(k<i){
			cout<<"*";
			k++;
		}
		
		}
		num=(num+1)-2*i;
		cout<<endl;
	}
}
