#include<iostream>
using namespace std;
int main(){

int i,j,l,k,n=5;
	int num=0;
for(i=1;i<=n;i++)
{

	char alpha = 64;
	 for(k=1;k<=n-i;k++)
    {
        cout <<"  ";
    }
    
	
    for(j=1;j<=i;j++)
    {
        num ++;
        cout << num <<" ";
    }
    for(l=1;l<i;l++){
	
        num--;
        cout << num <<" ";
		}
    cout << endl;
	}
}
