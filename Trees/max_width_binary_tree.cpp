#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left, *right;
    treeNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int maxWidth(treeNode *root)
{
    queue<pair<treeNode *, int>> q;
    int ans = INT_MIN;
    q.push({root, 0});
    while (!q.empty())
    {
        int minTerm = q.front().second;
        int first, last;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto p = q.front();
            q.pop();
            treeNode *node = p.first;
            int currId = p.second - minTerm;
            if (i == 0)
            {
                first = currId;
            }
            if (i == size - 1)
            {
                last = currId;
            }
            if (node->left)
            {
                q.push({node->left, currId * 2 + 1});
            }
            if (node->right)
            {
                q.push({node->right, currId * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
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
    cout<<maxWidth(root);
    return 0;
}