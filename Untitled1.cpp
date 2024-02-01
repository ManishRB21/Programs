#include <iostream>
using namespace std;

int main()
{

    int i, j, k, l, n;
    cout << "\nEnter the Range\n";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (k = i; k >= 1; --k)
        {
            cout << k;
        }
        for (l = 2; l < i + 1; ++l)
        {
            cout << l;
        }
        cout << "\n";
    }

}
  
  

    
