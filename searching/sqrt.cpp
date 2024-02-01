#include<iostream>
using namespace std;
int sqrt(int x){
	int i=1;
	while(i*i<=x){
		i++;
	}
	return(i-1);
}

int main(){
	int x;
	cout<<"enter no";
	cin>>x;
	cout<<"root "<<sqrt(x);
	}
