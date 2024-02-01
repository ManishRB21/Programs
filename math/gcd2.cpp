#include<iostream>
using namespace std;
int min(int a, int b){
	if(a>b)
	return b;
	
	else
	return a;
	
}
int main()
{
	int a,b;
	cout<<"enter 2 num";
	cin>>a>>b;
	int res=min(a,b);
	while(res>0){
	
	if(a%res==0 && b%res==0){
		break;
	}
	res--;
}
cout<<res;
}
