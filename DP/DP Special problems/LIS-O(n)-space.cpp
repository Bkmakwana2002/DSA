// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.

    int longestSubsequence(int n, int arr[])
    {
       // your code here
        vector<int> dp(n,1);
        int maxi = 1;
        for(int index= 0; index<n; index++)
        {
            for(int prevIndex = 0; prevIndex<index; prevIndex++)
            {
                if(arr[prevIndex]<arr[index])
                {
                    dp[index] = max(dp[index],dp[prevIndex]+1);
                }
            }
        }
        for(int i = 0; i<n; i++)
        {
            maxi = max(dp[i],maxi);
        }
        return maxi;
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