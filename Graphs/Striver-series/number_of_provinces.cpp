//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int i, int V, vector<bool> &vis, vector<int> graph[],vector<int> dfsV)
    {
        dfsV.push_back(i);
        vis[i] = true;
        for(auto x  : graph[i])
        {
            if(!vis[x])
            {
                dfs(x,V,vis,graph,dfsV);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n = adj.size();
        int m = adj[0].size();
        
        vector<int> graph[V];
        
        for(int i=0; i<V; i++)
        {
            for(int j = 0; j<V; j++)
            {
                if(adj[i][j] == 1 && i!=j)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        int cnt = 0;
        vector<int> dfsV;
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,V,vis,graph,dfsV);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends