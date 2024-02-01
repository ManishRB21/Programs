#include<iostream>
using namespace std;
int main(){
	int row;
	cin>>row;
	for(int i=row; i>=1;i--){
		for(int j=1; j<=2*row-1;j++){
			if(j>=row-(i-1) && j<=row+(i-1)){
				cout<<"*";
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
}
