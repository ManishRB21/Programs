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

node *insertany(node *&head, int pos, int x){
	node *temp= new node(x);
	if(pos==1){
		temp->next=head;
		return temp;
	}
	node *curr=head;
	for(int i=1; i<=pos-2 && curr!=NULL; i++){
		curr=curr->next;
	}
	if(curr==NULL){
		return head;
	}
	temp->next=curr->next;
	curr->next=temp;
	return head;
	
}

int search(node *&head, int x){
	int pos=1;
	node *curr=head;
	while(curr!=NULL){
		if(curr->data==x){
			return pos;
		}
		else{
			pos++;
			curr=curr->next;
		}
	}
	return -1;
}

void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main(){
	node *head= NULL;
	insertb(head,30);
	insertb(head,20);
	insertb(head,10);
	print(head);
	cout<<endl;
	insertany(head,2,50);
	insertany(head,5,60);
	print(head);
	cout<<endl;
	int n;
	cin>>n;
	cout<<"element found at pos "<<search(head, n);
}
