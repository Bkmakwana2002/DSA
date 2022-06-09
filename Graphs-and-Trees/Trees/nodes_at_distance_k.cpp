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

vector<int> nodesAtDistanceK(treeNode *root, treeNode *target, int k)
{
    unordered_map<treeNode *, bool> visited;
    queue<treeNode *> q;
    q.push(target);
    visited[target] = true;
    unordered_map<treeNode *, treeNode *> m = parentTraversal(root);
    int currDis = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (currDis == k)
        {
            break;
        }
        currDis ++;
        while (size--)
        {
            treeNode *temp = q.front();
            q.pop();
            if (target->left != NULL && visited[target->left] != true)
            {
                q.push(target->left);
                visited[target->left] = true;
            }
            if (target->right != NULL && visited[target->right] != true)
            {
                q.push(target->right);
                visited[target->right] = true;
            }
             if (m[target] != NULL && visited[m[target]] != true)
            {
                q.push(m[target]);
                visited[m[target]] = true;
            }
        }
    }
    vector<int> v;
    while(!q.empty())
    {
       v.push_back(q.front()->data);
       q.pop();
    }
    return v;
}

int main()
{
    treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    vector<int> v = nodesAtDistanceK(root,root->right,1);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}