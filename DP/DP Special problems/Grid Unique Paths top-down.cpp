#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    long long int numberOfPaths(int m, int n){
        // code here
        int dp[m][n];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up = 0;
                int left = 0;
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else{
                if(i>0)
                {
                    up = dp[i-1][j];
                }
                if(j>0)
                {
                    left = dp[i][j-1];
                }
                dp[i][j] = up+left;
            }
            }
        }
        return dp[m-1][n-1];
    }
};

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