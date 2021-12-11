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

bool palindrome(Node *head)
{
    stack<int> s;
    Node *temp = head;
    while (temp != NULL)
    {
        s.push(head->data);
        head = head->next;
    }
    while (head != NULL)
    {
        int i = s.top();
        s.pop();
        if (i != head->data)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}

void printNode(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 11; i++)
    {
        pushNode(&head, i);
    }
    cout << endl;
    cout << palindrome(head);
    return 0;
}