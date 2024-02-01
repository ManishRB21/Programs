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


void rprint(Node *head){
	if(head==NULL)
	return;
	cout<<head->data<<" ";
	rprint(head->next);
}


int main(){
	Node *head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);
	head->next->next->next = new Node(40);
	head->next->next->next->next = new Node(40);
	rprint(head);
	return 0;
}
