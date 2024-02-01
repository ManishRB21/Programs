#include <iostream>
using namespace std;
class Node
{
public:

int data;
Node *next;
Node *prev;

};

void push(Node** head, int newdata)

{
Node* newnode = new Node();
newnode->data = newdata;
newnode->prev = NULL;
newnode->next = (*head);
if((*head) != NULL)
(*head)->prev = newnode ;
(*head) = newnode;
}

void traverse(Node *node)
{
while(node != NULL){
cout << node->data << " ";
node = node->next;}
}

void revtraverse(Node **head){

	Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    while (tail != *head) {
   cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << tail->data << endl;;
}

int main(){

Node* head = NULL;
push(&head, 7);
push(&head, 5);
push(&head, 3);
push(&head, 2);
cout << "Original Linked list" << endl;
traverse(head);
cout << "\nReversed Linked list" << endl;
revtraverse(&head);
return 0;
}
