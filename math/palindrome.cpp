#include<iostream>
using namespace std;
int palindrome(int n){
	int rev=0;
	int temp=n;
	while(temp!=0){
		int ld= temp%10;
		rev=rev*10+ld;
		temp=temp/10;
	}
	cout<<rev;
	if(rev==n){
		cout<<"palindrome";
	}
	else{
		cout<<"not palindrome";
	}
}
int main(){
	int x;
	cout<<"number ";
	cin>>x;
	palindrome(x);	
}
