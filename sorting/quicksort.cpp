#include<iostream>
using namespace std;

void swap(int ar[], int i, int j){
	int temp=ar[i];
	ar[i]=ar[j];
	ar[j]=temp;
}

int partition(int ar[], int l, int r){
	int pivot=ar[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(ar[j]<pivot){
			i++;
			swap(ar,i,j);
		}
	}
	swap(ar,i+1,r);
	return i+1;
}

void quicksort(int ar[], int l, int r){
	if(l<r){
		int pi=partition(ar,l,r);
		quicksort(ar,l,pi-1);
		quicksort(ar,pi+1,r);
	}
}

int main(){
	int n=5;
	int ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	quicksort(ar,0,4);
		for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}
