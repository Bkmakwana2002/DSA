// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    vector<int> PrintlongestSubsequence(int n, int arr[])
    {
        // your code here
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 1;
        int lastIndex = 0;
        for(int i=0; i<n; i++)
        {
            hash[i] = i;
        }
        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (arr[ind] > arr[prev] && 1+dp[prev]>dp[ind])
                {
                    dp[ind] = 1+dp[prev];
                    hash[ind] = prev;
                }
            }
            if(dp[ind]>maxi)
            {
                maxi = dp[ind];
                lastIndex = ind;
            }
        }
        vector<int> lis(maxi);
        int index = 1;
        lis[0] = arr[lastIndex];
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            lis[index ++ ] = arr[lastIndex];
        }
        return lis;
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        vector<int> ans = ob.PrintlongestSubsequence(n, a);
    }
}
// } Driver Code Ends