#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define r 3
#define c 3
int median(int mat[][c]){
	int min=mat[0][0];
	int max=mat[0][c-1];
	for(int i=0;i<r;i++){
		if(mat[i][0]<min)
			min=mat[i][0];
		if(mat[i][c-1]>max)
			max=mat[i][c-1];
	}
	int medpos=(r*c+1)/2;
	while(min<max){
		int mid = min + (max - min) / 2;
		int midpos=0;
		for(int i=0;i<r;i++){
			midpos += upper_bound(mat[i], mat[i]+c, mid) - mat[i];
		}
		if(midpos<medpos)
		min=mid+1;
		else
		max=mid;
	}
	return min;
}
int main(){
	int mat[][c]={{1,10,20},
				{15,25,35},
				{5,30,40}};	
	cout<<median(mat);
return 0;
}
