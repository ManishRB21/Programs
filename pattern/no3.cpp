#include<iostream>
using namespace std;
int main(){
	int row;
	cin>>row;
	int no=1;
	for(int i=1; i<=row;i++){
		for(int j=1; j<=i;j++){
			cout<<no++<<" ";
		}
		cout<<endl;
	}
	
}
