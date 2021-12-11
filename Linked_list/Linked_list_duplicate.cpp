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

Node* duplicate(Node* head)
{
    Node* temp = head;
    while(temp->next!=NULL)
    {
        if(temp->data == temp->next->data)
        {
            Node* extra = temp->next->next;
            free(temp->next);
            temp->next = extra;
        }
        else 
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 6; i++)
    {
        int x;
        cin>>x;
        pushNode(x, &head);
    }
    printNode(head);
    cout<<endl;
    head = duplicate(head);
    printNode(head);
    return 0;
}