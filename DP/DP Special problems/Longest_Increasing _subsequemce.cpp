// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int f(int index, int prevIndex, int n , int a[], vector<vector<int>> &dp)
    {
        if(index == n)
        {
            return 0;
        }
        if(dp[index][prevIndex+1] != -1)
        {
            return dp[index][prevIndex+1];
        }
        int len;
        len = f(index+1,prevIndex,n,a,dp);
        if(prevIndex == -1 || a[index]>a[prevIndex])
        {
           len = max(len,f(index+1,index,n,a,dp) + 1);
         }
         return dp[index][prevIndex+1] = len;
        
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return f(0,-1,n,a,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends