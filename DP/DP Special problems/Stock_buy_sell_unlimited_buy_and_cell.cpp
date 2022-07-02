#include<bits/stdc++.h>
using namespace std;

long f(int index, int buy , int n, long arr[],vector<vector<int>>&dp)
{
    if(index == n)
    {
        return 0;
    }
    long profit = -1e+8;
    if(dp[index][buy] != -1)
    {
        return dp[index][buy];
    }
    if(buy == 1)
    {
        dp[index][buy] = max(-arr[index] + f(index+1,0,n,arr,dp),f(index+1,1,n,arr,dp));
    } 
    else if(buy == 0)
    {
        dp[index][buy] = max(arr[index] + f(index+1,1,n,arr,dp),f(index+1,0,n,arr,dp));
    }
    return dp[index][buy];
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    int buy = 1;
    int index = 0;
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return f(index,buy,n,values,dp);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}