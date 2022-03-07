#include <bits/stdc++.h>
using namespace std;

struct treeNode{
   int data;
   treeNode*left;
   treeNode*right;
   treeNode(int val)
   {
      data = val;
      left = NULL;
      right =NULL;
   }
};

void preOrderTraversal(treeNode* root) //time complexity = O(N) space complexity = O(N)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    treeNode* root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    preOrderTraversal(root);
    return 0;
}