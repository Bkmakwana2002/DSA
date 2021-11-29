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

int List_Lenght(Node* head)
{
    int ll = 0;
    while(head!=NULL)
    {
        head = head->next;
        ll++;
    }
    return ll;
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
    cout<<List_Lenght(head);
    return 0;
}