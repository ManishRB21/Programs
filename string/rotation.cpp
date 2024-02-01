#include<iostream>
using namespace std;

void rotation(string &t, string &p){
	int txt= t.length();
	int pat=p.length();
	for(int i=0;i<=(txt-pat);i++){
		int j;
		for(j = 0; j < pat; j++){
			if(t[i+j]!=p[j]){
				break;
			}
		}
		if(j==pat){
			cout<<" it is a rotated string ";
		}
		else
		cout<<" not a rotated string ";
	}
}


int main() {
   string t,p;
   getline(cin,t);
   string R= t+t;
   getline(cin,p);
   rotation(R,p);
}
