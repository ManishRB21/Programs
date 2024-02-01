#include<iostream>
using namespace std;
int permute(string s, int i=0){
	if(i==s.length()-1){
		cout<<s<<" ";
	}
	for(int j=i; j<s.length(); j++){
		swap(s[i], s[j]);
		permute(s,i+1);
		swap(s[j], s[i]);
		
	}
}
int main(){
	string s= "ABC";
	permute(s);
	return 0;
}
