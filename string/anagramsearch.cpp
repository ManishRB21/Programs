#include<iostream>
using namespace std;
#define C 256
bool compare(int counttxt[],int countpat[])
{
    for (int i=0; i<C; i++){
	
        if (counttxt[i] != countpat[i])
		{	
            return false;
		}
	}
	return true;	
}

int anagramsearch(string &s1, string &s2){
	int counttxt[C]={0};
	int countpat[C]={0};
	int txt= s1.length();
	int pat=s2.length();
	for(int i=0;i<pat;i++){
		counttxt[s1[i]]++;
		countpat[s2[i]]++;
	}
	for(int i=pat;i<txt;i++){
		if(compare(counttxt,countpat)){
			return 1;
		}
		counttxt[s1[i]]++;
		counttxt[s1[i-pat]]--;
	}
	return 0;
	
}


int main() {
   string s1, s2;
   getline(cin,s1);
   getline(cin,s2);
   cout<<anagramsearch(s1,s2);
}
