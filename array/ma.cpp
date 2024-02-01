#include<iostream>
using namespace std;
int majority(int ar[], int n){
		for(int i=0;i<n;i++){
			int count=0;
			for(int j=0;j<n;j++){
				if(ar[i]==ar[j])
				count++;
			}
			if(count>(n/2)){
			return i;
		} 
		
		}
	cout<<"no majority";	
}


int main(){
	int ar[100];
	int n=5;
	cout<<"enter array ";
	for(int i=0; i<n; i++){
		cin>>ar[i];
	}
	for(int i=0; i<n; i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	cout<<"majority element index :-";
	cout<<majority(ar,n);
}
	

