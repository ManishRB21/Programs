#include<iostream>
using namespace std;
int occurcount(int ar[], int n, int x){
	int count =0;
	for(int i=0; i<n;i++){
		if(ar[i]==x)
		count++;
	}
	return count;
}

int main(){
	int ar[100];
	int n=5,x;
	cout<<"enter array"<<endl;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	cin>>x;
	cout<<"occurence "<<occurcount(ar,n,x);
}
