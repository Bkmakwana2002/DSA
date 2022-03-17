#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* pushNode(Node** head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    newNode->next = *head;
    if(*head!=NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
    return *head;
}

Node* reverseList(Node* head)
{
    Node* temp = NULL;
    Node* current = head;
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp!=NULL)
    {
        head = temp->prev;
    }
    return head;
}

void printNode(Node* head)
{
  Node* temp = head;
  while(temp!=NULL)
  {
      cout<<temp->data<<" ";
      temp = temp->next;
  }
}

int main()
{
    Node* head = NULL;
    for(int i=0; i<11; i++)
    {
        pushNode(&head,i);
    }
    printNode(head);
    cout<<endl;
    head = reverseList(head);
    printNode(head);
    return 0;
}