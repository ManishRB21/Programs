#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int l=1;l<=k;l++){
				for(int j=1;j<=i;j++){
					cout<<"* ";
				}
				for(int s=n;s>i;s--){
					cout<<"  ";
				}
			}
			cout<<endl;
		}
	}
	
}
