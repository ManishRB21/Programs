#include<iostream>
using namespace std;
bool palindrome(string str){
	int begin=0;
	int end= str.length()-1;
	while(begin<end){
		if(str[begin]!=str[end]){
			return false;
		}
		begin++;
		end--;
	}
	return true;
}

int main(){
	string str;
	getline(cin,str);
	palindrome(str);
	if(palindrome(str)==1)
	cout<<"palindrome";
	else
	cout<<"not palindrome";
	return 0;
}
