#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
	node(int x){
		data=x;
		next=NULL;
	}
};

void insertb(node *&head, int x){
	node *temp= new node(x);
	temp->next=head;
	head=temp;
}

void deleteb(node *&head){
	if(head==NULL){
		return;
	}
	else{
		node *temp=head;
		head=head->next;
		delete temp;
		return;
		
	}
}


void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main(){
	node *head= NULL;
	insertb(head,10);
	insertb(head,20);
	insertb(head,30);
	insertb(head,40);
	print(head);
	cout<<endl;
	deleteb(head);
	print(head);
	
}
