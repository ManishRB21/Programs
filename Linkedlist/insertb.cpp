#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int x){
		data=x;
		next=NULL;
	}
};

void insertb(Node *&head, int n){
	Node *temp= new Node(n);
	temp->next=head;
	head=temp;
}

void print(Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main(){
	Node *head= NULL;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		insertb(head,x);
	}
	
	print(head);
	
}
