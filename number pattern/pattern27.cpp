#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int temp;
	for(int i=1;i<=n;i++){
		temp=i;
		for(int j=1;j<=i;j++){
			cout<<temp<<" ";
			temp=temp+n-j;
		}
		cout<<endl;
	}
}
