#include <bits/stdc++.h>
using namespace std;

int maxSum = 0;

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

bool checkTrees(treeNode *root1, treeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return (root1 == root2);
    }
    return (root1->data == root2->data) && checkTrees(root1->left, root2->left) && checkTrees(root1->right, root2->right);
}

int main()
{
    treeNode *root1 = new treeNode(1);
    root1->left = new treeNode(2);
    root1->right = new treeNode(3);
    root1->left->right = new treeNode(8);
    
    treeNode *root2 = new treeNode(1);
    root2->left = new treeNode(2);
    root2->right = new treeNode(3);
    root2->left->right = new treeNode(8);
    cout << checkTrees(root1, root2);
    return 0;
}