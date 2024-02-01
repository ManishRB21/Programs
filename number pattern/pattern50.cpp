#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int num=1;
	for(int i=n;i>=1;i--){
	     for(int j=i;j<n;j++){
	         cout<<j;
	     }
	     for(int j=1;j<=i;j++){
	         if(i==j)
	         cout<<"0";
	     }
	     for(int j=n-1;j>=i;j--){
	         cout<<j;
	     }
	cout<<endl;

}
}
