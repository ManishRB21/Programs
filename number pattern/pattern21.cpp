#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		int num=1;
		for(int j=1;j<=i;j++){
			if(num%2!=0){
				cout<<"1"<<" ";
			}
			else{
				cout<<"0"<<" ";
			}
			num++;
		}
		cout<<endl;
	}
	
}
