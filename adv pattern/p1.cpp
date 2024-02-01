 #include<iostream>
 using namespace std;
 
 int main(){
 	int n;
 	cin>>n;
 	
 	for(int i=1;i<=n;i++){
 		int num=1;
 		for(int s=i;s<n;s++){
 			cout<<"  ";
		 }
		 for(int j=1;j<2*i;j++){
 			cout<<num<<" ";
 			num++;
		 }
		 cout<<endl;
	 }
	 for(int i=n-1;i>=1;i--){
 		int num=1;
 		for(int s=i;s<n;s++){
 			cout<<"  ";
		 }
		 for(int j=1;j<2*i;j++){
 			cout<<num<<" ";
 			num++;
		 }
		 cout<<endl;
	 }
 }
