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
int main(){
	int x;
	cout<<"number ";
	cin>>x;
	cout<<prime(x);	
}
