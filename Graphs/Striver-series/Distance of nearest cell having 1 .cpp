//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    int vis[n][m];
	    queue<pair<pair<int,int>,int>> q;
	    vector<vector<int>> dis(n,vector<int>(m,-1));
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }
	            else{
	                vis[i][j] = 0;
	            }
	        }
	    }
	    int drow[] = {0,0,-1,1};
	    int dcol[] = {1,-1,0,0};
	    while(!q.empty())
	    {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        dis[row][col] = steps;
	        for(int i=0; i<4; i++)
	        {
	            int nRow = row + drow[i];
	            int nCol = col + dcol[i];
	            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol]!=1)
	            {
	                vis[nRow][nCol] = 1;
	                q.push({{nRow,nCol},steps+1});
	            }
	        }
	    }
	    return dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends