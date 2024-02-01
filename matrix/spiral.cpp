#include<iostream>
using namespace std;
#define R 4
#define C 4
int spiral(int mat[R][C]){
	int top=0, right= C-1, bottom=R-1, left=0;
	while(top<=bottom && left<=right){
		for(int i=left;i<=right;i++){
			cout<<mat[top][i]<<" ";
		}
			top++;
		for(int i=top;i<=bottom;i++){
			cout<<mat[i][right]<<" ";
		}
		right--;
	if(top<=bottom){
			for(int i=right;i>=left;i--){
			cout<<mat[bottom][i]<<" ";
		}
			bottom--;
	}
	if(left<=right){
		for(int i=bottom;i>=top;i--){
			cout<<mat[i][left]<<" ";
		}
		left++;
	}
	}
}
int main(){
	int mat[R][C];
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>mat[i][j];
	spiral(mat);
return 0;
}
}
}



