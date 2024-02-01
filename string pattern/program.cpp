#include<iostream>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	int n;
	cin>>n;
	int a=0;
	for(int i=0;i<n;i++){
		for(int sp=i;sp<n;sp++){
			cout<<" ";
		}
		for(int j=0;j<=i;j++){
			cout<<s[a++]<<" ";
			if(s[a]=='\0'){
				a=0;
			}
		}
		cout<<endl;
	}
	
}
