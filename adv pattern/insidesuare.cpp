#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			if((i%2==0 && i>=j) ||(j%2==0 && j>=i) || (i==0) ||(j==0)){
				cout<<" *";
			} 
			else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
}
