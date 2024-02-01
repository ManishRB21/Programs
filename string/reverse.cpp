#include<iostream>
using namespace std;

void reverse(string &s, int l, int r){
	while(l<=r){
		swap(s[l],s[r]);
		l++;
		r--;
	}
}
string reverseword(string &s){
	int start=0;
	int n= s.length();
	for(int end=0; end<n; end++){
		if(s[end]==' '){
			reverse(s,start,end-1);
			start=end+1;
		}
	}
	reverse(s,start,n-1);
	reverse(s,0,n-1);
	return s;
}


int main(){
	string s;
	getline(cin,s);
	string rev=reverseword(s);
	cout<<rev;
	return 0;
}
