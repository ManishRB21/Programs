 #include<iostream>
 using namespace std;
 
 int main(){
 	int n;
 	cin>>n;
 	char alpha ='A';
 	for(int i=1;i<=n;i++){
 		for(int s=i;s<n;s++){
 			cout<<"  ";
		 }
 		
		 for(int j=i;j>=1;j--){
 			cout<<char(alpha+j-1)<<" ";
		 }
		 for(int l=2;l<=i;l++){
 			cout<<char(alpha+l-1)<<" ";
		 }
		 cout<<endl;
	 }
 }
