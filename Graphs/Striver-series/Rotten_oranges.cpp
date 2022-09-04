//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                   q.push({{i,j},0});
                   vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int tm = 0;            
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nRow = drow[i] + row;
                int nCol = dcol[i] + col;
                if(nRow>=0 &&  nRow <n && nCol>=0 &&  nCol <m && grid[nRow][nCol] == 1 && vis[nRow][nCol]!=2)
                {
                    q.push({{nRow,nCol},t+1});
                    vis[nRow][nCol] = 2;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]!=2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return tm;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends