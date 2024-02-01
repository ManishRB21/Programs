#include<iostream>
using namespace std;
void subset(string s, string curr="", int i=0){
	int n = s.length();
	if(i==n){
		cout<<curr<<endl;
		return;
	}
	subset(s,curr, i+1);
	subset(s,curr+s[i], i+1);
}
int main(){
	string s="abc";
	subset(s);
	return 0;
}
