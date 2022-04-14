#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left, *right;
    treeNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int changeDigit(treeNode* root, int compare)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = changeDigit(root->left,compare);
    int right = changeDigit(root->right,compare);
    root->data  = max(left+right,max(root->data,compare));
    return root->data;
}

void changeTree(treeNode* root)
{
    changeDigit(root,1);
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
    return 0;
}