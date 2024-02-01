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

void deletel(node *&head){
	if(head==NULL){
		return;
	}
	if(head->next==NULL){
		delete head;
		return;
	}
	node *curr=head;
	while(curr->next->next!=NULL){
		curr=curr->next;
	}
	delete (curr->next);
	curr->next=NULL;
	return;
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
	deletel(head);
	print(head);
	
}
