// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
       for(int s=i;s<n;s++){
           cout<<" ";
       }
       for(int j=1;j<=i;j++){
           if(j==1 ||j==i|| i==n){
               cout<<j<<" ";
           }
           else{
               cout<<"  ";
           }
       }
       cout<<endl;
   }
}
