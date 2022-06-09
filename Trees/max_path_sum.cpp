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

int maxSumPath(treeNode *root, int &maxSum)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = maxSumPath(root->left, maxSum);
    int rightSum = maxSumPath(root->right, maxSum);
    maxSum = max(root->data + leftSum + rightSum, maxSum);
    return root->data + max(leftSum, rightSum);
}

int maxi(treeNode *root)
{
    int maxSum = INT_MIN;
    maxSumPath(root, maxSum);
    return maxSum;
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    cout << maxi(root);
    return 0;
}