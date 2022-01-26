#include <bits/stdc++.h>
using namespace std;

int t[4][51];

int tnapSact(int W, int wt[], int val[], int n)
{
    int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] +
                                t[i - 1][j - wt[i - 1]],
                                t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = 3;
    cout << tnapSact(W, wt, val, n);
    return 0;
}