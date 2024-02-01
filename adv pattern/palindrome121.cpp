 #include<iostream>
 using namespace std;
 
 int main(){
 	int n;
 	cin>>n;
 	
 	for(int i=1;i<=n;i++){
 		int num=0;
 		for(int s=i;s<n;s++){
 			cout<<"  ";
		 }
		for(int j=1;j<=i;j++){
 			num++;
			 cout<<num<<" ";
		 }
		 for(int l=1;l<i;l++){
 			num--;
 			cout<<num<<" ";
		 }
		 cout<<endl;
	 }
 	
 }
