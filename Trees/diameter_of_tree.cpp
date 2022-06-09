#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
    treeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(treeNode *root,int &d)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left, d);
    int rh = height(root->right, d);
    d = max(d, lh + rh);
    return 1 + max(lh,rh);
}

int diameter(treeNode *root)
{
    int d = 0;
    height(root, d);
    return d;
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    cout << diameter(root);
    return 0;
}