#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j%2==0){
				cout<<((n*j)+i+1)<<" ";
			}
			else{
				cout<<(n*(j+1)-i)<<" ";	
			}
		}
		cout<<endl;
	}
}
