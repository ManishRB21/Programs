#include<iostream>
using namespace std;

int main(){
	string l;
	getline(cin,l);
	int n=l.length();
	for(int i=0;i<n;i++){
		for(int s=i;s<n;s++){
			cout<<" ";
		}
		for(int j=0;j<=i;j++){
			cout<<l[j];
		}
		cout<<endl;
	}
	for(int i=n-2;i>=0;i--){
		for(int s=i;s<n;s++){
			cout<<" ";
		}
		for(int j=0;j<=i;j++){
			cout<<l[j];
		}
		cout<<endl;
	}
}
