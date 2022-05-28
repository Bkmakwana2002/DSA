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

void printNode(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* NewLL(Node* head, int x)
{
    Node* temp = new Node();
    temp->next = head;
    Node* slow = temp;
    Node* fast = temp;
    for(int i=0; i<x; i++)
    {
        fast = fast->next;
    }
    while(fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return temp->next;
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 11; i++)
    {
        pushNode(i, &head);
    }
    printNode(head);
    cout<<endl;
    int x;
    cin>>x;
    NewLL(head,x);
    printNode(head);
    return 0;
}