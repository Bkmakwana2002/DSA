#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *pushNode(int data, Node **head)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return *head;
}

Node *InsertAtEnd(int data, Node* head)
{
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->data = data;
    temp->next = newNode;
    newNode->next = NULL;
    return head;
}

void printNode(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 11; i++)
    {
        head = pushNode(i, &head);
    }
    printNode(head);
    cout<<endl;
    head = InsertAtEnd(11,head);
    printNode(head);
    return 0;
}