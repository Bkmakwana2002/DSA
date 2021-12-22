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

bool findLoop(Node* head)
{
    unordered_set <Node*> s;
    while(head!=NULL)
    {
        if(head->next = NULL)
        {
            return true;
        }
        s.insert(head);
        head = head->next;
    }
    return false;
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
    cout<<findLoop(head);
    return 0;
}