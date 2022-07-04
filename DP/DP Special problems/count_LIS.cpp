// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    unsigned long long int countSub(int nums[], int n)
    {
        // Your code goes here
        unsigned long long int  maxi = 1;
	    vector<unsigned long long int > dp(n,1),cnt(n,1);
	    for(unsigned long long int  i=0; i<n; i++)
	    {
	        for(unsigned long long int  j=0; j<i; j++)
	        {
	            if(nums[i]>nums[j] && dp[j]+1>dp[i])
	            {
	                dp[i] = dp[j]+1;
	                cnt[i] = cnt[j];
	            }
	            else if(dp[j]+1 == dp[i] && nums[i]>nums[j]){
	                cnt[i] = cnt[i] + cnt[j];
	            }
	        }
	        maxi = max(maxi,dp[i]);
	    }
	    unsigned long long int  nos = 0;
	    for(unsigned long long int  i=0; i<n; i++)
	    {
	        if(dp[i] == maxi)
	        {
	            nos = nos + cnt[i];
	        }
	    }
	    return nos;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(unsigned long long int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.countSub(a,n)<<endl;
    }
}
  // } Driver Code Ends