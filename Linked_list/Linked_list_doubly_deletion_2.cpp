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
    if(*head!=NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
    return *head;
}

Node* deleteNode(Node* head)
{
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    temp->prev = NULL;
    free(temp);
    return head;
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
        pushNode(&head,i);
    }
    printNode(head);
    head = deleteNode(head);
    cout<<endl;
    printNode(head);
    return 0;
}