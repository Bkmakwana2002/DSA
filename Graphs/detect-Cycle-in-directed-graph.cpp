//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.

    bool cycle(int n, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis, int i)
    {
        vis[i] = true;
        dfsVis[i] = true;
        for (auto x : adj[i])
        {
            if (!vis[x])
            {
                if (cycle(n, adj, vis, dfsVis, x))
                {
                    return true;
                }
            }
            else if (vis[x] == true && dfsVis[x] == true)
            {
                return true;
            }
        }
        dfsVis[i] = false;
        return false;
    }

    bool isCyclic(int n, vector<int> adj[])
    {
        // code here
        vector<bool> vis(n, false);
        vector<bool> dfsVis(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (cycle(n, adj, vis, dfsVis, i))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends