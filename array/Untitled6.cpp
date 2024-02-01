// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
void ispalin(string &s){
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        cout<<s[i];
    }
}
int main(){
    string s;
    getline(cin,s);
    ispalin(s);
}
