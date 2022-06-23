#include <bits/stdc++.h>
using namespace std;

int f(int index, int last, vector<vector<int>> &p, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (last != i)
            {
                maxi = max(maxi, p[0][i]);
            }
        }
        return maxi;
    }
    if (dp[index][last] != -1)
    {
        return dp[index][last];
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (last != i)
        {
            int points = p[index][i] + f(index - 1, i, p, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[index][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, 3, points, dp);
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