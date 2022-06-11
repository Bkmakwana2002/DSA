#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

unordered_map<treeNode *, treeNode *> parentTraversal(treeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    queue<treeNode *> q;
    unordered_map<treeNode *, treeNode *> m;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            treeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                m[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                m[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    return m;
}

int minTime(treeNode* root, treeNode* target)
{
    unordered_map<treeNode*,treeNode*> m;
    m = parentTraversal(root);
    queue<treeNode*> q;
    unordered_map<treeNode*,bool> visited;
    q.push(target);
    visited[target] = true;
    int mintime = 0;
    bool flag = false;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            treeNode* temp = q.front();
            q.pop();
            if(temp->left && visited[temp->left]!=true)
            {
                flag = true;
                visited[temp->left] = true;
                q.push(temp->left);
            }
            if(temp->right && visited[temp->right]!=true)
            {
                flag = true;
                visited[temp->right] = true;
                q.push(temp->right);
            }
            if(m[temp] && visited[m[temp]]!=true)
            {
                flag = true;
                visited[m[temp]] = true;
                q.push(m[temp]);
            }
        }
        if(flag)
        {
            mintime ++;
        }
    }
    return mintime;
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    cout<<minTime(root,root->left);
}