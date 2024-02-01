#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
};

node *newnode(int data){
	node *temp= new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

void inorder(node *node){
	if(node==NULL){
		return;
	}
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

void preorder(node *node){
	if(node==NULL){
		return;
	}
	cout<<node->data<<" ";
	preorder(node->left);
	preorder(node->right);
}

void postorder(node *node){
	if(node==NULL){
		return;
	}
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<" ";
}

int height(node *root){
	if(root==NULL){
		return 0;
	}
	return max(height(root->left), height(root->right))+1;
}

int main()
{
    node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout << "\nInorder traversal of binary tree is \n";
    inorder(root);
 cout << "\npreorder traversal of binary tree is \n";
    preorder(root);
    cout << "\npostorder traversal of binary tree is \n";
    postorder(root);
 cout << "\nheight is \n";
 cout<<height(root);
    return 0;
}
