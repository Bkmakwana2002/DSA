#include <bits/stdc++.h>
using namespace std;

int getMaximumProfit(int arr[], int n)
{
    int buy = 1;
    int index = 0;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    int profit;
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy == 1)
            {
                profit = max(dp[index+1][0] - arr[index], dp[index+1][1]);
            }
            else
            {
               profit = max(arr[index] + dp[index+2][1], dp[index+1][0]);
            }
            dp[index][buy] = profit;
        }
    }
   return dp[0][1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<getMaximumProfit(arr,n);
    return 0;
}