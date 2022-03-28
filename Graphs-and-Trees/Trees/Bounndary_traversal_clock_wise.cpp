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
    if (root->left != NULL)
    {
        leftTraversal(root->left, ans);
        ans.push_back(root->data);
    }
    else if (root->right != NULL)
    {
        leftTraversal(root->right, ans);
        ans.push_back(root->data);
    }
}

void leafTraversal(treeNode *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    leafTraversal(root->right, ans);
    if (root->right == NULL && root->left == NULL)
    {
        ans.push_back(root->data);
    }
    leafTraversal(root->left, ans);
}

void rightTraversal(treeNode *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    if (root->right != NULL)
    {
        ans.push_back(root->data);
        rightTraversal(root->right, ans);
    }
    else if (root->left != NULL)
    {
        ans.push_back(root->data);
        rightTraversal(root->left, ans);
    }
}

vector<int> printBoundary(treeNode *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    rightTraversal(root->right, ans);
    leafTraversal(root, ans);
    leftTraversal(root->left, ans);
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