#include<iostream>
using namespace std;
#define R 4
#define C 4
int search(int mat[R][C],int x){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(mat[i][j]==x){
			cout<<"element fount at position "<<i<<j;
			return 1;	
		}
		}
	}
	cout<<"not found";
	return 0;
}
int main(){
	int mat[R][C]={{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{13,14,15,16}};	
	int x;
	cin>>x;
	search(mat,x);
return 0;
}



