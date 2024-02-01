#include<iostream>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	int n=s.length();
	for (int i=0; i<n; i++) {
        for (int j=0; j<=n/2; j++) {
          if(i == n/2 ){
            cout<<s;
            break;
          } else {
            if(j == n/2)
              cout<<s[i];
            else
              cout<<" "; // one space
          }
        }
        cout<<endl; // new line
      }
}
