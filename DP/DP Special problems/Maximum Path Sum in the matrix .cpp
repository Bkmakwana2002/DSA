#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &m, int i, int j, vector<vector<int>> &dp)
{
    if(j<0 || j>=m[0].size())
    {
        return -1e9;
    }
    if(i == 0)
    {
       return m[i][j];
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = m[i][j] + f(m,i-1,j,dp);
    int diag1 = m[i][j] + f(m,i-1,j-1,dp);
    int diag2 = m[i][j] + f(m,i-1,j+1,dp);
    
    return dp[i][j] = max(up,max(diag1,diag2));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e8;
    vector<vector<int>> dp(n,vector<int> (m,-1));
    for(int i=0; i<m; i++)
    {
        int res = f(matrix,n-1,i,dp);
        maxi = max(maxi,res);
    }
    return maxi;
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
        cout << getMaxPathSum(v) << endl;
    }
    return 0;
    return 0;
}