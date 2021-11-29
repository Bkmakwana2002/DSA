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

int NthNode(Node* head, int x)
{
    int z = 10-x;
    while(head!=NULL && z>0)
    {
        head = head->next;
        z--;
    }
    return head->data;
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
    cout<<NthNode(head,x);
    return 0;
}