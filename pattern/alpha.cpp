#include<iostream>
using namespace std;
int main(){
	int row;
	cin>>row;
	char alphabet = 'A';
	for(int i=1; i<=row;i++){
		for(int j=1; j<=i;j++){
			cout<<alphabet<<" ";
		}
		alphabet++;
		cout<<endl;
	}
	
}
