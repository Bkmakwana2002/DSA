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

void bottomView(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<pair<treeNode *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        treeNode *node = p.first;
        int line = p.second;
        m[line] = node->data;
        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }
    for (auto p : m)
    {
        cout << p.second << " ";
    }
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    bottomView(root);
    return 0;
}