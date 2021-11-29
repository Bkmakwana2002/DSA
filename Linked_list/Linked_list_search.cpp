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

bool Search(Node* head, int x)
{
    bool ans = false;
    while(head!=NULL)
    {
        if(head->data == x)
        {
            ans = true;
            break;
        }
        else
        {
            head = head->next;
        }
    }
  return ans;
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
    cout<<Search(head,x);
    return 0;
}