#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* pushNode(int data, Node **head)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return *head;
}

Node* solve(Node* first,Node* second)
{
    Node* curr1 = first;
    Node* curr2 = second;
    Node* next1 = curr1->next;
    Node* next2 = curr2->next;
    if(next1 == NULL)
    {
        curr1->next = curr2;
        return first;
    }
    while(next1!=NULL && next2!=NULL)
    {
        if((curr2->data>=curr1->data) && (curr2->data<=next1->data))
        {
           curr1->next = curr2;
           next2 = curr2->next;
           curr2->next = next1;

           curr1 = next1;
           curr2 = next2;   
        }
        else{
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* mergeList(Node* first, Node* second)
{
    if(first->data > second->data)
    {
        return solve(second, first);
    }
    else{
        return solve(first, second);
    }
}

void printNode(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* first = NULL;
    Node* second = NULL;
    first = pushNode(1, &first);
    first = pushNode(4, &first);
    first = pushNode(5, &first);
    
    second = pushNode(2, &second);
    second = pushNode(3, &second);
    second = pushNode(6, &second);
    mergeList(first, second);
    printNode(first);
}