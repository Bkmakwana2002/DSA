#include <bits/stdc++.h>
using namespace std;

int t[4][51];

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
    memset(t, -1, sizeof(t));
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (t[n][W] != -1)
    {
        return t[n][W];
    }
    if (wt[n - 1] > W)
        return t[n][W] = knapSack(W, wt, val, n - 1);
    else
        return t[n][W] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = 3;
    cout << knapSack(W, wt, val, n);
    return 0;
}