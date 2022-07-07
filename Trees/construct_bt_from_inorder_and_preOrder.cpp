// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:

    int findPos(int in[], int n,int ele)
    {
       for(int i=0; i<n; i++)
       {
          if(in[i] == ele)
          {
            return i;
          }
       }
       return -1;
    }

    Node *solve(int in[], int pre[], int n , int index, int inS, int inE)
    {
        if (index >= n || inS > inE)
        {
            return NULL;
        } 
        int element = pre[index++];
        int pos = findPos(in,n,element);
        Node* newNode = new Node(element);
        newNode->left = solve(in,pre,n,index,inS,pos-1);
        newNode->right = solve(in,pre,n,index,pos+1,inE);
        return newNode;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        int index = 0;
        Node *ans = solve(in, pre, n, index, 0, n - 1);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends