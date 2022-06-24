// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
   long long int solve(int m, int n,vector<vector<int>> &dp)
   {
        if(m == 1 && n == 1)
        {
            return 1;
        }
        if(m <= 0 || n <= 0)
        {
            return 0;
        }
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }
        return dp[m][n] = (solve(m-1,n,dp)%1000000007+solve(m,n-1,dp)%1000000007)%1000000007;
   }
   
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve( m, n,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends