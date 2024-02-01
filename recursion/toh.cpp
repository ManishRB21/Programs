#include<iostream>
using namespace std;
void toh(int n, char source, char des, char aux){
	if(n==1){
		cout<<"move disk 1 from "<<source<<" to "<<des<<endl;
		return;
	}
	toh(n-1, source, aux, des);
	cout<<"move disk "<<n<<" from "<<source<<" to "<<des<<endl;
	toh(n-1, aux, des, source);
}
int main(){
	int n;
	cout<<"enter no";
	cin>>n;
	toh(n,'A','C','B');
	return 0;
}
