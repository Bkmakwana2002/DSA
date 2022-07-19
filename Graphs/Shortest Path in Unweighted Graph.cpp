#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<int> adj[], int n)
{
    vector<int> vis(n,false);
    vector<int> dis(n,INT_MAX);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    dis[0] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto i : adj[x])
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i] = true;
                dis[i] = 1 + dis[x];
            }
        }
    }
    return dis;
}