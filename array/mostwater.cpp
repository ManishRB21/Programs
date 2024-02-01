#include<iostream>
using namespace std;
int mostwater(int ar[], int n){
	int water =0, left=0, right=n-1;
	while(left<right){
		int curwater= (right-left)*(min(ar[left],ar[right]));
		water= max(water, curwater);
		if(ar[left]<ar[right])
		left++;
		else
		right--;
	}
	return water;
}

int main(){
	int ar[100];
	int n=9;
	cout<<"enter array ";
	for(int i=0; i<n; i++){
		cin>>ar[i];
	}
	for(int i=0; i<n; i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	cout<<"most rain "<<mostwater(ar,n)<<" units";
	
}
