#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &mat, vector<vector<int>> &dp, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return mat[i][j];
    }
    if (i < 0 || j < 0)
    {
        return 1e9;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int left = mat[i][j] + f(mat, dp, i - 1, j);
    int up = mat[i][j] + f(mat, dp, i, j - 1);
    return dp[i][j] = min(left, up);
}

int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(grid, dp, n - 1, m - 1);
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
        cout << minSumPath(v) << endl;
    }
    return 0;
}