#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n;i++){
		int no=1;
		for(int j=1; j<=2*n-1;j++){
			if(j>=n-(i-1) && j<=n+(i-1)){
			
		cout<<no++;
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
}
