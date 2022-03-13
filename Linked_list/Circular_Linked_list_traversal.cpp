#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   Node* next;
   Node(int x)
   {
       data = x;
       next = NULL;
   }
};

Node* pushNode(Node** head, int data)
{
    Node* newNode = new Node(data);
    Node* temp = *head;
    newNode->next =*head;
    if(*head!=NULL)
    {
        while(temp->next!=*head)
        {
           temp = temp->next;   
        }
        temp->next = newNode;
    }
    else{
        newNode->next = newNode;
    }
    *head = newNode;
    return *head;
}

void printNode(Node* head)
{
    Node* temp = head;
    cout<<temp->data<<" ";
    temp = temp->next;
    while(temp!=head)
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
    return 0;
}