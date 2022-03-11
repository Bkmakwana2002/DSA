#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


class Solution
{
    public:
    
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        while(curr!=NULL)
        {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    void insertAtEnd(Node* &head,Node* &tail, int data)
    {
        Node* temp = new Node(data);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    
    Node* add(Node* first,Node* second)
    {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        while(first!=NULL && second!=NULL)
        {
            int sum = first->data + second->data + carry;
            int digit = sum%10;
            insertAtEnd(ansHead,ansTail,digit);
            carry = sum/10;
            first = first->next;
            second = second->next;
        }
        
        while(first!=NULL)
        {
            int sum = first->data + carry;
            int digit = sum%10;
            insertAtEnd(ansHead,ansTail,digit);
            carry = sum/10; 
            first = first->next;
        }
        while(second!=NULL)
        {
            int sum = second->data + carry;
            int digit = sum%10;
            insertAtEnd(ansHead,ansTail,digit);
            carry = sum/10; 
            second = second->next;
        }
        while(carry>0)
        {
            int sum = carry;
            int digit = sum%10;
            insertAtEnd(ansHead,ansTail,digit);
            carry = sum/10; 
        }
        return ansHead;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       first = reverse(first);
       second = reverse(second);
       
       Node* ans = add(first,second);
       
       ans = reverse(ans);
       return ans;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
