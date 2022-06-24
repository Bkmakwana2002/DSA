#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int t[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                t[i][j] = grid[i][j];
            }
            else
            {
                int up = INT_MAX;
                int left = INT_MAX;
                if (i > 0)
                {
                    up = grid[i][j] + t[i - 1][j];
                }
                if (j > 0)
                {
                    left = grid[i][j] + t[i][j - 1];
                }
                t[i][j] = min(up, left);
            }
        }
    }
    return t[n - 1][m - 1];
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