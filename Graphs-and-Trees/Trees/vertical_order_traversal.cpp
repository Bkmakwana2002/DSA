// to do later
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

vector<vector<int>> veticalTraversal(treeNode* root)
{
   queue<pair<treeNode*,pair<int,int>>> q;
   map<int,map<int,multiset<int>>> m;
   q.push({root,{0,0}});
   while(!q.empty())
   {
       auto p = q.front();
       q.pop();
       treeNode* node = p.first;
       int x = p.second.first;
       int y = p.second.first;
       m[x][y].insert(node->data);
       if(node->left)
       {
           q.push({node->left,{x-1,y+1}});
       }
       if(node->right)
       {
           q.push({node->left,{x+1,y+1}});
       }
   }
   vector<vector<int>> ans;
   for(auto p : m)
   {
       vector<int> col;
       for(auto q : p.second)
       {
           col.insert(col.end(),q.second.begin(),q.second.end());
       }
       ans.push_back(col);
   }
   return ans;
}

int main()
{
    treeNode* root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->right = new treeNode(8);
    vector<vector<int>> ans = veticalTraversal(root);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j = 0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
    }
    return 0;
}