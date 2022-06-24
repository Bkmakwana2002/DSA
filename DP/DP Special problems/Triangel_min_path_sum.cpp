#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>& t,vector<vector<int>>& dp ,int n, int i, int j)
{
    if(i == n-1)
    {
        return t[i][j];
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int down = t[i][j] + f(t,dp,n,i+1,j);
    int diag = t[i][j] + f(t,dp,n,i+1,j+1);
    
    return dp[i][j] = min(down,diag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(triangle,dp,n,0,0);
}

int main()
{
     int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int i = 0; i < m; i++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }
        cout << minimumPathSum(v,n) << endl;
    }
    return 0;
    return 0;
}