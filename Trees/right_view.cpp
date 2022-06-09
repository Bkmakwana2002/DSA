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

void rightView(treeNode *root, int level, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    if (level == v.size())
    {
        v.push_back(root->data);
    }
    rightView(root->right, level + 1,v);
    rightView(root->left, level + 1,v);
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    vector<int> v;
    rightView(root, 0, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}