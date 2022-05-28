#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   Node* next;
   Node(int data)
   {
       data = data;
       next = NULL;
   }
};

Node* push(Node** head,int data)
{
    Node* newNode = new Node(data);
    newNode->next = *head;
    *head = newNode;
    return *head;
}

int loopLength(Node* slow)
{
    int count = 0;
    Node* temp = slow;
    while(temp->next!=slow)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int loopNode(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(slow && fast&& fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return loopLength(slow);
        }
    }
    return 0;
}

void printNode(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    head->next->next->next->next->next = head;
    cout<<loopNode(head);
    return 0;
}