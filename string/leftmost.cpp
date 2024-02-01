#include<iostream>
using namespace std;
#define n 256
int leftmost(string &s1){
	int count[n]={0};
	for(int i=0;i<s1.length();i++){
		count[s1[i]]++;
	}
		for(int i=0; i<n; i++){
		if(count[s1[i]]>1)
		return i;
	}
	return -1;
}


int main(){
	string s1;
	getline(cin,s1);
	cout<<"index "<<leftmost(s1);
	return 0;
}
