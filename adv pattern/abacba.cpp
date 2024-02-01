 #include<iostream>
 using namespace std;
 
 int main(){
 	int n;
 	cin>>n;
 	char alpha ='A';
 	for(int i=1;i<=n;i++){
 		for(int j=i;j>=1;j--){
 			cout<<char(alpha+j-1);
		 }
		 cout<<endl;
	 }
 }
