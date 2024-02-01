#include<iostream>
using namespace std;
int main(){
	int row;
	cin>>row;
	
	for(int i=1; i<=row;i++){
		char alphabet = 'A';
		for(int j=1; j<=i;j++){
			cout<<alphabet++;
		}
		cout<<endl;
	}
	
}
