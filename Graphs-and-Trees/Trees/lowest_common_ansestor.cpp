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

treeNode* LCA(treeNode* root, treeNode* p,treeNode* q)
{
    if(root == NULL || root == p || root == q)
    {
        return root;
    }
    treeNode* left = LCA(root->left,p,q);
    treeNode* right = LCA(root->right,p,q);
    if(left == NULL)
    {
        return right;
    }
    if(right == NULL)
    {
        return left;
    }
    else 
        return root;
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(2);
    root->left->left = new treeNode(3);
    root->left->right = new treeNode(4);
    root->right->left = new treeNode(4);
    root->right->right = new treeNode(3);
    treeNode* ans = LCA(root,root->left->left,root->right->right);
    cout<<ans->data;
    return 0;
}