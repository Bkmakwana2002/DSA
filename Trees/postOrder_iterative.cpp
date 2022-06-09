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

vector<int> postOrderTravesal(treeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    stack<treeNode *> s1;
    stack<int> s2;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root->data);
        if (root->left != NULL)
        {
            s1.push(root->left);
        }
        if (root->right != NULL)
        {
            s1.push(root->right);
        }
    }
    vector<int> v;
    while (!s2.empty())
    {
        v.push_back(s2.top());
        s2.pop();
    }
    return v;
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    vector<int> v = postOrderTravesal(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}