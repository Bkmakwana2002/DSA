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

int main()
{
    treeNode* root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    return 0;
}