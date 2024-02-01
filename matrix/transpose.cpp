#include<iostream>
using namespace std;
#define R 4
#define C 4
int transpose(int mat[R][C]){
	for(int i=0;i<R;i++){
		for(int j=i+1;j<C;j++){
			swap(mat[i][j],mat[j][i]);
		}
	}
}
int main(){
	int mat[R][C]={{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{13,14,15,16}};	
	transpose(mat);
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
return 0;
}



