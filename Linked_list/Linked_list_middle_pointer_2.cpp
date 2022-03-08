#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* pushNode(Node** head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return *head;
}

Node* reverLinkedList(Node* head)
{
    Node* fastPointer = head;
    Node* slowPointer = head;
    while(fastPointer!=NULL && fastPointer->next!=NULL)
    {
       fastPointer = fastPointer->next->next;
       slowPointer = slowPointer->next;
    }
    return slowPointer;
}

void printNode(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
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
        pushNode(&head, i);
    }
    printNode(head);
    cout<<endl;
    Node* midPonter = new Node();
    midPonter = reverLinkedList(head);
    cout<<midPonter->data;
    return 0;
}