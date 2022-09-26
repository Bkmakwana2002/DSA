//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    struct node
    {
        int u;
        int v;
        int wt;
        node(int first, int second, int weight)
        {
            u = first;
            v = second;
            wt = weight;
        }
    };

    static bool comp(node a, node b)
    {
        return a.wt < b.wt;
    }

    int findPar(int u, vector<int> &parent)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = findPar(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findPar(u, parent);
        v = findPar(v, parent);
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<node> grph;
        for (int it = 0; it < V; it++)
        {   
            int u = it;
            for (auto x : adj[it])
            {
                grph.push_back(node(it, x[0], x[1]));
            }
        }
        sort(grph.begin(), grph.end(), comp);
        vector<int> parent(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(V, 0);
        int cost = 0;
        for (auto it : grph)
        {
            int ue = it.u;
            int ve = it.v;
            int wte = it.wt;
            if (findPar(ue, parent) != findPar(ve, parent))
            {
                unionSet(ue, ve, parent, rank);
                cost = cost + wte;
            }
        }
        return cost;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends