#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i==(n/2)+1){
			for(int j=1;j<=n;j++){
				cout<<"*";
			}
		}
		else{
			for(int j=1;j<=n/2;j++){
				cout<<" ";
			}
			cout<<"*";
		}
		cout<<endl;
	}
}
