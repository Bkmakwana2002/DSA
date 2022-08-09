#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        int mod = 1000000007;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            int oneStep = dp[i - 1];
            int secondStep = 0;
            if (n >= 2)
            {
                secondStep = dp[i - 2];
            }
            dp[i] = (oneStep + secondStep) % mod;
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}