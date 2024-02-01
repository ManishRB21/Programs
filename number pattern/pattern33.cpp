#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int num=1;
	for(int i=n;i>=1;i--){
	     for(int j=i;j<=n;j++){
	       cout<<j;
	    }
	for(int j=n-1;j>=i;j--){
	cout<<j;
	}   
	    cout<<endl;
	}
    for(int i=2;i<=n;i++){
	     for(int j=i;j<=n;j++){
	       cout<<j;
	    }
	for(int j=n-1;j>=i;j--){
	cout<<j;
	}   
	    cout<<endl;
	}
}
