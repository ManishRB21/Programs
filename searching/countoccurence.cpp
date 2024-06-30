// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int x){
    int low = 0, high= n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>x){
            high=mid-1;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else{
            if(mid==0 || arr[mid]!=arr[mid-1]){
                return mid;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int lastOcc(int arr[], int n, int x){
    int low = 0, high= n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>x){
            high=mid-1;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else{
            if(mid==n-1 || arr[mid]!=arr[mid+1]){
                return mid;
            }
            else{
                low=mid+1;
            }
        }
    }
    return -1;
}


int main() {
    
    // Write C++ code here
    int n,x,res;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int first = firstOcc(arr, n, x);
    if(first == -1)
    return 0;
    else
    res = lastOcc(arr, n, x)-first+1;
    cout<<res;
}
