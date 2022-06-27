#include <bits/stdc++.h>
using namespace std;

int f(int r,int c,int i,int j1, int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
{
    if(j1<0 || j2<0 || j1>=c || j2>=c)
    {
        return -1e8;
    }
    if(i == r-1)
    {
        if(j1 == j2)
        {
            return grid[i][j1];
        }
        else{ 
            return grid[i][j1]+grid[i][j2];
        }
    }
    if(dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int maxi = -1e8;
    for(int di = -1; di<=1; di++)
    {
        for(int dj = -1; dj<=1; dj++)
        {
            int val;
            if(j1 != j2)
            {
                val = grid[i][j1] + grid[i][j2];
            }
            else{
                val = grid[i][j1];
            }
            val = val + f(r,c,i+1,j1+di,j2+dj,grid,dp);
            maxi = max(maxi, val);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(r,c,0,0,c-1,grid,dp);
}

int main()
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();
    int m = points[0].size();
    cout << maximumChocolates(n,m,points);
}