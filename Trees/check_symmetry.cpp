#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left = NULL;
    treeNode *right = NULL;
    treeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isSymmetryCheck(treeNode* left,treeNode* right)
{
    if(left == NULL && right == NULL)
    {
        return true;
    }
    if(left == NULL || right == NULL)
    {
        return false;
    }
    if(left->data != right->data)
    {
        return false;
    }
    return isSymmetryCheck(left->left,right->right) && isSymmetryCheck(left->right,right->left);
}

bool isSymmetry(treeNode* root)
{
   return root==NULL || isSymmetryCheck(root->left,root->right);
}

int main()
{
    treeNode* root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(2);
    root->left->left = new treeNode(3);
    root->left->right = new treeNode(4);
    root->right->left = new treeNode(4);
    root->right->right = new treeNode(3);
    cout<<isSymmetry(root);
    return 0;
}