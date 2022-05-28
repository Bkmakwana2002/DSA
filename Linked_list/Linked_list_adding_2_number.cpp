#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* pushNode(Node** head,int data)
{
    Node* newNode = new Node(data);
    newNode->next = *head;
    *head = newNode;
    return newNode;
}

Node* addTwoNumbers(Node* head1, Node* head2)
{
    int carry = 0;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(head1!=NULL || head2!=NULL || carry)
    {
        int sum = 0;
        if(head1!=NULL)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2!=NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum/10;
        Node* newNode = new Node(sum%10);
        temp->next = newNode;
        temp = temp->next;
    }
    return dummy->next;
}

void printNode(Node* head)
{
    while(head!=NULL)
    {
       cout<<head->data<<" ";
       head = head->next;
    }
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    for(int i=0; i<5; i++)
    {
        pushNode(&head1,i);
    }
    for(int i=5; i<9; i++)
    {
        pushNode(&head2,i);
    }
    printNode(head1);
    cout<<endl;
    printNode(head2);
    cout<<endl;
    Node* node = addTwoNumbers(head1,head2);
    printNode(node);
}