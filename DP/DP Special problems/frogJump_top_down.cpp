#include<bits/stdc++.h>
using namespace std;


int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i=1; i<n; i++)
    {
        int x = INT_MAX;
        int y = dp[i-1] + abs(heights[i]-heights[i-1]);
        if(i-2>=0)
        {
           x = dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        dp[i] = min(x,y);
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
    cout<<frogJump(n,v);
    return 0;
}