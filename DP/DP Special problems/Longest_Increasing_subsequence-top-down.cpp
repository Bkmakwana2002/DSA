// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.

    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       for(int index = n-1 ; index>=0; index--)
       {
           for(int prevIndex = index-1; prevIndex>=-1; prevIndex--)
           {
               int len;
               len = dp[index+1][prevIndex+1];
               if(prevIndex == -1 || a[index]>a[prevIndex])
               {
                  len = max(len,dp[index+1][index+1]+1);
                }
              dp[index][prevIndex+1] = len;
           }
       }
       return dp[0][-1+1];
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