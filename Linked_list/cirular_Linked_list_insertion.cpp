#include <bits/stdc++.h>
using namespace std;

struct circularNode
{
    int data;
    circularNode *next;
};

circularNode *head = NULL;
circularNode *tail = NULL;

void pushCirularNode(int data)
{
    circularNode *newNode = new circularNode();
    if (head == NULL)
    {
        newNode->data = data;
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void printNode()
{
    circularNode *current = head;
    if (current == NULL)
    {
        cout << "LIST IS EMPTY";
    }
    else
    {
        do
        {
            cout << current->data<<" ";
            current = current->next;
        } while (current != head);
    }
}

int main()
{
    pushCirularNode(1);
    pushCirularNode(2);
    pushCirularNode(3);
    pushCirularNode(4);
    pushCirularNode(5);
    printNode();
    return 0;
}