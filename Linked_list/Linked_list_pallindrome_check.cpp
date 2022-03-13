#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:

    bool isPalindrome(Node *head)
    {
        stack<int> s;
        Node* temp = head;
        while(temp!=NULL)
        {
            s.push(temp->data);
            temp = temp->next;
        }
        Node* temp2 = head;
        while(temp2!=NULL)
        {
            int val = s.top();
            s.pop();
            if(temp2->data!=val)
            {
                return false;
            }
            temp2 = temp2->next;
        }
        return true;
    }
};

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;

        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;

        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
