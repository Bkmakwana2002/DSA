#include <bits/stdc++.h>
using namespace std;

int t[7][8];

int LCS(string x, string y, int n, int m)
{
    memset(t, -1, sizeof(t));
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (t[n][m] != -1)
    {
        return t[n][m];
    }
    if (x[n - 1] == y[m - 1])
    {
        return t[n][m] = 1 + LCS(x, y, n - 1, m - 1);
    }
    return t[n][m] = max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
}

int main()
{
    string x = "abcdgh";
    string y = "abcdfhr";
    int n = x.length();
    int m = y.length();
    cout << LCS(x, y, n, m);
    return 0;
}