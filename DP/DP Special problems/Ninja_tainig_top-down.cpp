#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &p)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // base case initilaization
    dp[0][0] = max(p[0][1], p[0][2]);
    dp[0][1] = max(p[0][0], p[0][2]);
    dp[0][2] = max(p[0][1], p[0][0]);
    dp[0][3] = max(p[0][1], max(p[0][2], p[0][0]));

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[i][j] = 0;
            int maxi = 0;

            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                {
                    dp[i][j] = max(dp[i][j],p[i][k]+dp[i-1][k]);
                }
            }
        }
    }
    return dp[n-1][3];
}

int main()
{

    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();
    cout << ninjaTraining(n, points);
    return 0;
}