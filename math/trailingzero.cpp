#include<iostream>
using namespace std;
int countzero(int x){
	int res=0;
	for(int i=5; i<=x; i=i*5){
		res= res+(x/i);
	}
	cout<<res;
}
int main(){
	int x;
	cout<<"number ";
	cin>>x;
	countzero(x);	
}
