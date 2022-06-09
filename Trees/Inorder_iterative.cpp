#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* right;
  Node* left;
  Node(int x)
  {
      data = x;
      right = NULL;
      left = NULL;
  }
};

vector<int> inOrder(Node* root)
{
    vector<int> ans;
    stack<Node*> st;
    Node* temp = root;
    while(true) 
    {
        if(temp!=NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty() == true)
            {
                break;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(8);
    for(int i=0; i<inOrder(root).size(); i++)
    {
        cout<<inOrder(root)[i]<<" ";
    }
    return 0;
}