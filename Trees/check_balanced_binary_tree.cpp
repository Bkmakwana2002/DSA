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

int maxHeight(treeNode* root) 
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);
    if(abs(lh-rh)>1)
    {
        return -1;
    }
    return 1+max(lh, rh);
}

int main()
{
    treeNode* root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    if(maxHeight(root) == -1)
    {
        cout<<false;
    }
    else{
        cout<<true;
    }
    return 0;
}