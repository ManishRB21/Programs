#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=n;i>=1;i--){
		for(int s=i;s<n;s++){
			cout<<s ;
		}
		for(int s=1;s<=i;s++){
			cout<<"5" ;
		}
		cout<<endl;
	}
}
