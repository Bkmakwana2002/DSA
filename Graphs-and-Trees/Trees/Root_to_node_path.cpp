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

bool getPath(treeNode *root, int data, vector<int> &ans)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->data);
    if (root->data == data)
    {
        return true;
    }
    if (getPath(root->left, data, ans) || getPath(root->right, data, ans))
    {
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> returnPath(treeNode *root, int x)
{
    vector<int> ans;
    getPath(root, x, ans);
    return ans;
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
    vector<int> ans = returnPath(root, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}