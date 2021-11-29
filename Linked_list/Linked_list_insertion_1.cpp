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

Node *InsertAtBeg(int data, Node** head)
{
    Node* newNode = new Node();
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

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 11; i++)
    {
        head = pushNode(i, &head);
    }
    printNode(head);
    cout<<endl;
    head = InsertAtBeg(11,&head);
    printNode(head);
    return 0;
}