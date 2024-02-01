#include<iostream>
using namespace std;
int subseq(string &str1, string &str2){
	int n= str1.length();
	int m= str2.length();
	int j=0;
	for(int i=0; i<n && j<m; i++){
		if(str1[i]==str2[j])
		j++;
	}
	if(j==m)
	cout<<"its a subsequence";
	else
	cout<<"not a subsequence";
}


int main(){
	string str1, str2;
	getline(cin,str1);
	getline(cin,str2);
	subseq(str1, str2);
	return 0;
}
