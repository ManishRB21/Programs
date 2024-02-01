#include<iostream>
using namespace std;
bool rotation(string &s1,string &s2){
	if(s1.length()!=s2.length())
	return false;
	
	return ((s1+s2).find(s2)!=string::npos);
}

int main() {
   string s1,s2;
   getline(cin,s1);
   getline(cin,s2);
   cout<<rotation(s1,s2);
}
