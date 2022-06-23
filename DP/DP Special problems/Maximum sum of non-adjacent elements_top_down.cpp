#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    for(int i=1; i<n; i++)
    {
        int pick = dp[i-2]+nums[i];
        int notPick = dp[i-1];
        dp[i] = max(pick,notPick);
    }
    return dp[n-1];
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<maximumNonAdjacentSum(v);
}