#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>> &edges, int source, int des)
{
    unordered_map<int, vector<int>> m;
    for (auto x : edges)
    {
        vector<int> temp = x;
        int u = temp[0];
        int v = temp[1];

        m[u].push_back(v);
        m[v].push_back(u);
    }

    vector<bool> vis(n, false);

    queue<int> q;
    q.push(source);
    vis[source] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        vector<int> temp = m[v];
        for (int i = 0; i < temp.size(); i++)
        {
            if (!vis[temp[i]])
            {
                vis[temp[i]] = true;
                q.push(temp[i]);
            }
        }
    }
    return vis[des];
}