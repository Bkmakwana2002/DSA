// using flyod's cycle detection algo

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* push(Node** head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return *head;
}

bool detectLoop(Node* head)
{
    Node* fastNode = head;
    Node* slowNode = head; 
    while(slowNode && fastNode)
    {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
        if(fastNode == slowNode)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    head->next->next->next->next = head;
    cout<<detectLoop(head);
    return 0;
}