 #include<iostream>
 using namespace std;
 
 int main(){
 	int n;
 	cin>>n;
 	int num =0;
 	for(int i=1;i<=n;i++){
 		for(int s=i;s<n;s++){
 			cout<<"  ";
		 }
		 for(int j=i;j>=1;j--){
		 	cout<<j<<" ";
		 }
		 for(int l=2;l<=i;l++){
		 	cout<<l<<" ";
		 }
	cout<<endl;	 
	 }
 	
 }
