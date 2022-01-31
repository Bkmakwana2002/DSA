#include <bits/stdc++.h>
using namespace std;

int t[9][9];

int Longest_repeating_SubSequence(int n, string x)
{
    for (int i = 0; i <= n; i++)
    {
        t[i][0] == 0;
    }
    for (int j = 0; j <= n; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == x[j - 1] && i != j)
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    return t[n][n];
}

int main()
{
    string x = "aabebcdd";
    int n = x.length();
    cout << Longest_repeating_SubSequence(n, x);
    return 0;
}