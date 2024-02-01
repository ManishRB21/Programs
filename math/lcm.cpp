#include<iostream>
using namespace std;
int min(int a, int b){
	if(a>b)
	return a;
	
	else
	return b;
	
}
int main()
{
	int a,b;
	cout<<"enter 2 num";
	cin>>a>>b;
	int res=max(a,b);
	while(res>0){
	
	if(res%a==0 && res%b==0){
		break;
	}
	res++;
}
cout<<res;
}
