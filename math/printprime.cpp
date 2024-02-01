#include<iostream>
using namespace std;
int prime(int x){
	if(x==1){
		return false;
	}
	for(int i=2; i*i<=x; i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

int printprime(int x){
	for(int i=2;i<=x;i++){
		if(prime(i)){
			cout<<i<<"\n";
		}
	}
}
int main(){
	int x;
	cout<<"number ";
	cin>>x;
	printprime(x);	
}
