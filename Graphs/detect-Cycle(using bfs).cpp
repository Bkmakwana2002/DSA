// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.

    bool check(int i, int n, vector<int> adj[], vector<bool> &vis)
    {
        queue<pair<int, int>> q;
        q.push({i, -1});
        vis[i] = true;
        while (!q.empty())
        {
            int index = q.front().first;
            int par = q.front().second;
            q.pop();
            for (auto it : adj[index])
            {
                if (!vis[it])
                {
                    q.push({it, index});
                }
                else
                {
                    if (par != it)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);
        for (int i = 0; i <= V; i++)
        {
            if (!vis[i])
            {
                if (check(i, V, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends