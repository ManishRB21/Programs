#include<iostream>
using namespace std;

void pattern(string &t, string &p){
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
			cout<<i<<" ";
			i=i+pat;
		}
		else if(j==0){
			i++;
		}
		else{
			i=i+j;
		}
	}
}


int main() {
   string t,p;
   getline(cin,t);
   getline(cin,p);
   pattern(t,p);
}
