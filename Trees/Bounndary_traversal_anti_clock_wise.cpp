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

void leftTraversal(treeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        ans.push_back(root->data);
        leftTraversal(root->left, ans);
    }
    else if (root->right != NULL)
    {
        ans.push_back(root->data);
        leftTraversal(root->right, ans);
    }
}

void leafTraversal(treeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    leafTraversal(root->left, ans);
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    leafTraversal(root->right, ans);
}

void rightTraversal(treeNode *root, vector<int> &ans)
{
    if (root->right != NULL)
    {
        rightTraversal(root->right, ans);
        ans.push_back(root->data);
    }
    if (root->left != NULL)
    {
        rightTraversal(root->left, ans);
        ans.push_back(root->data);
    }
}

vector<int> printBoundary(treeNode *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    leftTraversal(root->left, ans);
    leafTraversal(root, ans);
    rightTraversal(root->right, ans);
    return ans;
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    vector<int> ans = printBoundary(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}