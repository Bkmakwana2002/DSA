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

vector<int> zigZag(treeNode *root)
{
    queue<treeNode *> q;
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    q.push(root);
    int f = 1;
    while (!q.empty())
    {
        vector<int> temp;

        int sz = q.size();

        while (sz--) 
        {
            treeNode *t = q.front();
            temp.push_back(t->data);
            q.pop();

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }

        if (f % 2 == 0)
        {
            reverse(temp.begin(), temp.end());
        }

        for (int i = 0; i < temp.size(); i++)
        {
            ans.push_back(temp[i]);
        }

        f++;
    }

    return ans;
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);

    vector<int> ans = zigZag(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}