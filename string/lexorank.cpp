#include<iostream>
using namespace std;
#define C 256
int fact(int n){
	if(n==0)
	return 1;
	
	return n*fact(n-1);
}

int lex(string &s){
	int res=1;
	int count[C]={0};
	int n=s.length();
	int mul=fact(n);
	for(int i=0;i<n;i++){
		count[s[i]]++;
	}
	for(int i=1;i<C;i++){
		count[i]=count[i]+count[i-1];
	}
	
	for(int i=0;i<n;i++){
		mul = mul/(n-i);
		res= res+count[s[i]-1]*mul;
		for(int j=s[i];j<C ;j++)
		count[j]--;
	}
	return res;
	
}

int main() {
   string s;
   getline(cin,s);
   cout<<lex(s);
}
