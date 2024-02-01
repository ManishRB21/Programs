// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
//   string s;
//   getline(cin,s);
//   int n=s.length();
   int n;
   cin>>n;
  
   for(int i=1;i<=n;i++){
        char a='A';
       for(int j=n;j>=i;j--){
           cout<<a++;
       }
       a-=2;
       for(int j=n-1;j>=i;j--){
           cout<<a--;
       }
       cout<<endl;
   }
}
