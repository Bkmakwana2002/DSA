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
    while(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* newHead = reverLinkedList(head->next);
    Node* nextHead = head->next;
    nextHead->next = head;
    head->next = NULL;
    return newHead;
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
    for(int i=0; i<10; i++)
    {
        pushNode(&head, i);
    }
    printNode(head);
    cout<<endl;
    head = reverLinkedList(head);
    printNode(head);
    return 0;
}