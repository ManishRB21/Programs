#include<iostream>
using namespace std;
int count(int x){
	int res=0;
	while(x>0){
		x=x/10;
		res++;
	}
	cout<<res;
}
int main(){
	int x;
	cout<<"number ";
	cin>>x;
	count(x);	
}
