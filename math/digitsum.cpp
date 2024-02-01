#include<iostream>
using namespace std;
int digitsum(int n){
	int r, sum=0;
	while(n!=0){
		r=n%10;
		sum=sum+r;
		n=n/10;
	}
	cout<<sum;
}

int main(){
	int x;
	cout<<"number ";
	cin>>x;
	digitsum(x);	
}
