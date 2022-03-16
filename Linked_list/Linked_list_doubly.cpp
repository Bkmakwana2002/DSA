#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* pushNode(int data,Node** head)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if(*head= NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
    return *head;
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
        pushNode(i,&head);
    }
    printNode(head);
    return 0;
}