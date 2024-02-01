#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(j%2==0){
				cout<<1+j*n-(j-1)*j/2+i-j<<" ";
			}
			else{
				cout<<1+j*n-(j-1)*j/2+n-1-i<<" ";
			}
		}
		cout<<endl;
	}
}
