#include<bits/stdc++.h>
using namespace std;

bool cycle(int i, int n, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &dfsVis, vector<bool> &prevVis)
{
    vis[i] = true;
    dfsVis[i] = true;
    vector<int> data = graph[i];

    for (auto x : data)
    {
        if (!vis[x])
        {
            if (cycle(x, n, graph, vis, dfsVis, prevVis))
            {
                return prevVis[i] = true;
            }
        }
        else if (vis[x] && dfsVis[x])
        {
            return prevVis[i] = true;
        }
    }
    dfsVis[i] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> vis(n, false);
    vector<bool> dfsVis(n, false);
    vector<bool> prevVis(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cycle(i, n, graph, vis, dfsVis, prevVis);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!prevVis[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}