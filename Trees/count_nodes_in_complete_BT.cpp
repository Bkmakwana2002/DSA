#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
    treeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int leftheight(treeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    while (root)
    {
        count++;
        root = root->left;
    }
    return count;
}

int rightheight(treeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    while (root)
    {
        count++;
        root = root->right;
    }
    return count;
}

int countNodes(treeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = leftheight(root);
    int rh = rightheight(root);
    if (lh == rh)
    {
        return pow(2, lh) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->left = new treeNode(8);
    cout << countNodes(root);
}