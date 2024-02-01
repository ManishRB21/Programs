// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
   string s;
   getline(cin,s);
   int n=s.length();
   int a=0;
   for(int i=1;i<=n;i++){
       for(int s=i;s<n;s++){
           cout<<" ";
       }
       for(int j=1;j<=2*i-1;j++){
           cout<<s[a];
       }
       a++;
       cout<<endl;
   }
}
