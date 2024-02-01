#include<iostream>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	int count[26]={0};
	for(int i=0;i<str.length();i++){
		count[str[i]-'a']++;
	}
	for(int i=0;i<str.length();i++){
		if(count[str[i]-'a']!=0)
		cout<<char[i+'a']<<" "<<count[str[i]-'a']<<endl;
		count[str[i]-'a']=0;
	}
}
