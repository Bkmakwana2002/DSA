#include<iostream>

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


int intersectPoint(Node* head1, Node* head2)
{
   Node *a=head1,*b=head2;
   Node *a1=head1,*b1=head2;
   int ans;
   if(head1==NULL or head2==NULL)return -1;
   int l1=0;
   int l2=0;
   while(a!=NULL)
   {
      a = a->next;
      l1++;
   }
   while(b!=NULL)
   {
      b = b->next;
      l2++;
   }
   if(l1>l2)
   {
       int forward = l1-l2;
       while(forward>0)
       {
           a1 = a1->next;
           forward--;
       }
   }
   if(l1<l2)
   {
       int forward = l2-l1;
       while(forward>0)
       {
           b1 = b1->next;
           forward--;
       }
   }
   while(a1!=b1)
   {
       a1= a1->next;
       b1 = b1->next;
   }
   return b1->data;
   
}

