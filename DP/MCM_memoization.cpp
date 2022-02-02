#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int mcm_memo(int arr[], int n, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (t[i][j] != -1)
    {
        return t[i][j];
    }
    t[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        t[i][j] = min(t[i][j], mcm_memo(arr,n,i, k) + mcm_memo(arr,n,k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
    }
    return t[i][j];
}

int mcm_solve(int arr[], int n)
{
    int i = 1;
    int j = n - 1;
    return mcm_memo(arr, n, i, j);
}

int main()
{
    memset(t, -1, sizeof(t));
    int arr[] = {1, 2, 3, 4, 3};
    int n = 5;
    cout << mcm_solve(arr, n);
    return 0;
}