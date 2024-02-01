 #include<iostream>
 using namespace std;
 
 int main(){
 	int n;
 	cin>>n;
 	int num=1;
 	for( int i=1;i<=n;i++ ) 
    {
        for( int j=i;j<n;j++ )
        {
            cout<<"    ";
        }
        for( int j=1;j<(i*2);j++ )
        {
            cout<<"  "<<num*num;
            num++;
        }
       cout<<endl;
	 }
 }
