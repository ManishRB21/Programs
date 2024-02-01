#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int num=1;
	for(int i=1;i<=n;i++){
	     for(int j=1;j<=i;j++){
	       cout<<num;
	    }
	    num++;
	    cout<<endl;
	}
    for(int i=n-1;i>=1;i--){
	     for(int j=1;j<=i;j++){
	       cout<<num;
	    }
	    num++;
	    cout<<endl;
	}
}
