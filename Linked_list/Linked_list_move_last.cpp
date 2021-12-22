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

void printNode(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *moveLast(Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next!=NULL)
    {
        swap(temp->data,temp->next->data);
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 11; i++)
    {
        pushNode(&head, i);
    }
    printNode(head);
    cout << endl;
    head = moveLast(head);
    printNode(head);
    return 0;
}