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
int primefactor(int n){
	for(int i=2; i<n; i++){
		if(prime(i)){
			int x=i;
			while(n%x==0){
				cout<<i<<"\n";
				x=x*i;
			}
		}
	}
}

int main(){
	int n;
	cout<<"number ";
	cin>>n;
	cout<<primefactor(n);	
}
