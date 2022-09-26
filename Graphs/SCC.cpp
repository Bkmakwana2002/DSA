//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfsTopo(int i, vector<int> adj[], stack<int> &st, vector<bool> &vis)
	{
	    vis[i] = true;
	    for(auto x: adj[i])
	    {
	        if(!vis[x])
	        {
	            dfsTopo(x,adj,st,vis);
	        }
	    }
	    st.push(i);
	}
	void dfs(int i, vector<int> adj[],vector<bool> &vis)
	{
	    vis[i] = true;
	    for(auto x: adj[i])
	    {
	        if(!vis[x])
	        {
	            dfs(x,adj,vis);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here 
        stack<int> st;
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfsTopo(i,adj,st,vis);
            }
        }
        vector<int> revG[V];
        for(int i=0; i<V; i++)
        {
            vis[i] = false;
            for(auto x: adj[i])
            {
                revG[x].push_back(i);
            }
        }
        int c = 0;
        while(!st.empty())
        {
            int x = st.top();
            st.pop();
            if(!vis[x])
            {
                c++;
                dfs(x,revG,vis);
            }
        }
      return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends