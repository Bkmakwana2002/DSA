#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    vector<int> dp(105);
    int n = s.size();
    dp[0] = 1;
    dp[1] = (s[0] == '0') ? 0 : 1;
    for (int i = 2; i < n + 1; i++)
    {
        int d = s[i - 1] - '0';
        int dd = 10 * (s[i - 2] - '0') + (s[i - 1] - '0');

        if (d >= 1)
        {
            dp[i] += dp[i - 1];
        }
        if (dd >= 10 && dd <= 26)
        {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}