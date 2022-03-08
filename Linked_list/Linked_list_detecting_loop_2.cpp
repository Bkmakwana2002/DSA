// using flag

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  int flag;
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
    Node* temp = head;
    while(temp)
    {
        if(temp->flag == 1)
        {
            return true;
        }
        temp->flag = 1;
        temp = temp->next;
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