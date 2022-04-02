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

void topView(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    map<int, int> m;
    queue<pair<treeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        treeNode *node = p.first;
        int line = p.second;
        if (m.find(line) == m.end())
        {
            m[line] = node->data;
        }
        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }
    for(auto p : m)
    {
        cout<<p.second<<" ";
    }
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    topView(root);
    return 0;
}