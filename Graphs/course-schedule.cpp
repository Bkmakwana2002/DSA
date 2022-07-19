#include <bits/stdc++.h>
using namespace std;

bool cycle(int i, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis)
{
    vis[i] = true;
    dfsVis[i] = true;

    vector<int> data = adj[i];
    for (auto x : data)
    {
        if (!vis[x])
        {
            if (cycle(x, adj, vis, dfsVis))
            {
                return true;
            }
        }
        else if (vis[x] && dfsVis[x])
        {
            return true;
        }
    }
    dfsVis[i] = false;
    return false;
}

bool canFinish(int n, vector<vector<int>> &pre)
{
    vector<int> adj[n];
    for (auto x : pre)
    {
        vector<int> data = x;
        int a = data[0];
        int b = data[1];
        adj[a].push_back(b);
    }

    vector<bool> vis(n, false);
    vector<bool> dfsVis(n, false);

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            if (cycle(i, adj, vis, dfsVis))
            {
                return false;
            }
        }
    }
    return true;
}