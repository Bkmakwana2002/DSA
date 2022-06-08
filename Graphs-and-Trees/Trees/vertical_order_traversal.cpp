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
      treeNode* temp = p.first;
      int vertical = p.second.first;
      int level = p.second.second;
      m[vertical][level].insert(temp->data);
      if(temp->left != NULL)
      {
         q.push({temp->left,{vertical-1,level+1}});
      }
      if(temp->right != NULL)
      {
          q.push({temp->right,{vertical+1,level+1}});
      }
  }
  vector<vector<int>> ans;
  for(auto it = m.begin(); it!=m.end(); it++)
  {
      vector<int> v;
      for(auto it1 = it->second.begin(); it1!= it->second.end(); it1++)
      {
        for(auto it2 = it1->second.begin(); it2!=it1->second.end(); it2++)
        {
            v.push_back(*it2);
        }
      }
      ans.push_back(v);
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