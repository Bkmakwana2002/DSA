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

Node* detectLoop(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        if(temp->flag == 1)
        {
            return temp;
        }
        temp->flag = 1;
        temp = temp->next;
    }
    return NULL;
}

Node* firstNode(Node* head)
{
    Node* start = head;
    Node* loopMeet = detectLoop(head);
    if(loopMeet != NULL)
    {
       while(start != loopMeet)
       {
           start = start->next;
           loopMeet = loopMeet->next;
       }
       return start;
    }
    return NULL;
}

int main()
{
    Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    head->next->next->next->next = head;
    cout<<detectLoop(head)->data;
    cout<<endl;
    cout<<firstNode(head)->data;
    return 0;
}