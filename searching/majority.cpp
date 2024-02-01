#include<iostream>
using namespace std;

int majority(int ar[], int n){
    int count=1;
    int res=0;
    for(int i=1;i<n;i++){
        if(ar[res]==ar[i]){
            count++;
        }
        else{
            count--;
        }
    if(count==0){
        res=i;
        count=1;
    }
    }
    return ar[res];
}
int main(){
    int n=5,x;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    cout<<majority(ar,n);
    
}
