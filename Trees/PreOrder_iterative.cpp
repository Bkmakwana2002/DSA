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

vector<int> preOrder(Node* root)
{
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) 
    {
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right!=NULL)
        {
            st.push(temp->right);
        }
        if(temp->left!=NULL)
        {
            st.push(temp->left);
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
    for(int i=0; i<preOrder(root).size(); i++)
    {
        cout<<preOrder(root)[i]<<" ";
    }
    return 0;
}