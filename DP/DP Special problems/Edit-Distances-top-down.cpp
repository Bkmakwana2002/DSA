// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int mod = 1000000007;
 
    int editDistance(string x, string y) {
        // Code here
        int n = x.size();
        int m = y.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0; i<n+1; i++)
        {
            dp[i][0] = i;
        }
        for(int i=0; i<m+1; i++)
        {
            dp[0][i] = i;
        }
        dp[0][0] = 0;
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(x[i-1] == y[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int ins = 1 + dp[i][j-1]%mod;
                    int del = 1 + dp[i-1][j]%mod;
                    int rep = 1 + dp[i-1][j-1]%mod;
                    dp[i][j] = min(ins,min(del,rep));
                }
            }
        }
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends