#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &h, vector<int> &dp)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    int lh = f(n-1,h,dp) + abs(h[n]-h[n-1]);
    int rh = INT_MAX;
    if(n-2>=0)
    {
       rh = f(n-2,h,dp) + abs(h[n]-h[n-2]); 
    }
    return dp[n] = min(lh,rh);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
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
    cout<<frogJump(n,v);
    return 0;
}