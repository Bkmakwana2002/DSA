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

vector<vector<int>> LevelOrder(treeNode *root)
{
    vector<vector<int>> v;
    queue<treeNode *> q;
    if (root == NULL)
    {
        return v;
    }
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            treeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        v.push_back(level);
    }
    return v;
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    vector<vector<int>> v = LevelOrder(root);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}