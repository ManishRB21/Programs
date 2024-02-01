#include <iostream>
using namespace std;

int main()
{

    int i, j, k, l, n;
    cout << "\nEnter the Range\n";
    cin >> n;
    cout<<" ";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (j=1, k=2*i-1; j<=2*i-1;j++,k--)
        {
            if(j<=k)
            cout << j;
            else
            cout<<k;
        }
        
        cout << "\n";
        cout<<" ";
    }

}
  
  

    
