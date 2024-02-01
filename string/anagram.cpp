#include<iostream>
using namespace std;
#define n 256
bool anagram(string &s1, string &s2){
	if(s1.length()!=s2.length())
	return false;
	int count[n]={0};
	for(int i=0;i<s1.length();i++){
		count[s1[i]]++;
		count[s2[i]]--;
	}
	for(int i=0; i<n; i++){
		if(count[i]!=0)
		return false;
	}
	return true;
}


int main(){
	string s1, s2;
	getline(cin,s1);
	getline(cin,s2);
	anagram(s1, s2);
	if(anagram(s1,s2)==1)
	cout<<"anagram";
	else
	cout<<"not anagram";
	return 0;
}
