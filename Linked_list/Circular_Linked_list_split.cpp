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
    newNode->next = *head;
    Node* temp = *head;

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

void splitList(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    Node* temp = head;
    while(fast->next!=head && fast!=head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* h1 = head;
    Node* h2 = slow->next;
    slow->next = h1;
    Node* curr = h2;
    while(curr->next!=head)
    {
        curr = curr->next;
    }
    curr->next = h2;
    printNode(h1);
    cout<<endl;
    printNode(h2);
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
    splitList(head);
    return 0;
}