// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int mod = 1000000007;
  
   int f(int i, int j, string x, string y,vector<vector<int>> &dp)
   {
       if(i<0)
       {
           return j+1;
       }
       if(j<0)
       {
           return i+1;
       }
       if(dp[i][j] != -1)
       {
           return dp[i][j];
       }
       if(x[i] == y[j])
       {
           return dp[i][j] =  f(i-1,j-1,x,y,dp)%mod;
       }
       int ins = 1 + f(i, j-1,x,y,dp)%mod;
       int del = 1 + f(i-1,j,x,y,dp)%mod;
       int rep = 1 + f(i-1,j-1,x,y,dp)%mod;
       return dp[i][j] = min(ins,min(del,rep));
   }
  
    int editDistance(string x, string y) {
        // Code here
        int n = x.size();
        int m = y.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,x,y,dp);
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