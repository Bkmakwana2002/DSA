#include <bits/stdc++.h>
using namespace std;

int mcm_solve(int arr[], int n, int i, int j)
{
    int ans = INT_MAX;
    int temp_ans;
    if (i >= j)
    {
        return 0;
    }
    for (int k = i; k <= j-1; k++)
    {
        temp_ans = mcm_solve(arr, n, i, k) + mcm_solve(arr, n, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        if (temp_ans < ans)
        {
            ans = temp_ans;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = 5;
    int i = 1;
    int j = n - 1;
    cout << mcm_solve(arr, n, i, j);
    return 0;
}