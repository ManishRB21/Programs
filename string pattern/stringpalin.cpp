#include<iostream>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	int n=s.length();
	for (int i=0; i<n; i++) {
		for(int j=0;j<=i;j++){
			cout<<s[j];
		}
		for(int j=i-1;j>=0;j--){
			
			cout<<s[j];
		}
        cout<<endl; // new line
      }
}
