// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  void dfs(int node, vector<bool>&vis, int n,vector<int> graph[],vector<int> &dfsV)
{
   dfsV.push_back(node);
   vis[node] = true;
   for(auto it:graph[node])
   {
      if(!vis[it])
      {
         dfs(it,vis,n,graph,dfsV);
      }
   }
}
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> graph[]) {
        // Code here
        vector<bool> vis(n, false);
   vector<int> dfsV;
   for (int i = 0; i < n; i++)
   {
      if (!vis[i])
      {
         dfs(i, vis, n, graph,dfsV);
      }
   }
   return dfsV;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends