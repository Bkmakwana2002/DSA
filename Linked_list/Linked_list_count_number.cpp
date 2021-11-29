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

int count(Node *head, int x)
{
    int c = 0;
    while (head != NULL)
    {
        if (x == head->data)
        {
            head = head->next;
            c++;
        }

        else
        {
            head = head->next;
        }
    }
    return c;
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 11; i++)
    {
        pushNode(i, &head);
    }
    printNode(head);
    cout << endl;
    int x;
    cin>>x;
    cout << count(head,x);
    return 0;
}
