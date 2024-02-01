#include<iostream>
using namespace std;
int pow(int n){
	while(n!=1){
		if(n%2!=0){
			return 0;
			}	
		n=n/2;	
	}
	return 1;
}
int main(){
	int x;
	cout<<"number ";
	cin>>x;
	if(pow(x))
	cout<<"power of 2";	
	else
	cout<<"not power of 2";
}


