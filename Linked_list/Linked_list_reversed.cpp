#include<bits/stdc++.h>
using namespace std;

struct Node{
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

Node* reverseList(Node* head)
{
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev= curr;
        curr = next;
    }
    return prev;
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