#include<iostream>
using namespace std;
void divisor(int n){
	for(int i=1;i<=n;++i){
		if(n%i==0){
			cout<<i<<"\n";
		}
	}
}
int main(){
	int x;
	cout<<"number ";
	cin>>x;
	divisor(x);	
}
