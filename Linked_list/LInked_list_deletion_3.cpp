#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *pushNode(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return *head;
}

Node* delete_At_Pos(Node** head, int pos)
{
    Node* temp = *head;
    for(int i=0; i<pos-1; i++)
    {
        temp = temp->next;
    }
    Node* temp1 = temp->next->next;
    free(temp->next);
    temp->next = temp1;
    return *head;
}

void printNode(Node *head)
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
    Node *head = NULL;
    for (int i = 0; i < 11; i++)
    {
       head = pushNode(&head, i);
    }
    printNode(head);
    cout<<endl;
    int pos;
    cin>>pos;
    head = delete_At_Pos(&head,pos);
    printNode(head);
    return 0;
}