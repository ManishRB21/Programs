#include <iostream>
using namespace std;
 
int main()
{
   char str[20];
   int n, a = 0;
 
   cin>>str;
   
   cin>>n;
 
   for (int i = 0; i <n; i++)
   {
      for (int j = 0; j <= n-i; j++)
         cout<<" ";
 
      for (int k = 0; k <= i; k++)
      {
         cout<<str[a++]<<" ";
 
         if (str[a] == '\0')
            a = 0;
      }
 
      cout<<endl; 
   }
}
