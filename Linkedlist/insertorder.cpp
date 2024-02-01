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

Node *insertl(Node *&head, int n){
	Node *temp= new Node(n);
	if(head==NULL)
   {
     head=temp;
   } 
  else
   {
     Node *cur=head;
     while(cur->next!=NULL)
      {
       cur=cur->next;
      }
     cur->next=temp;
}
}

Node *insertorder(Node *&head, int x){
	Node *temp= new Node(x);
	if(head==NULL){
		return temp;
	}
	if(x<head->data){
		temp->next=head;
		return temp;
	}
	Node *curr=head;
	while(curr->next!=NULL && curr->next->data<x){
		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next=temp;
	return head;
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
		insertl(head,x);
	}
	print(head);
	insertorder(head, 15);
	cout<<endl;
	print(head);
	
}
