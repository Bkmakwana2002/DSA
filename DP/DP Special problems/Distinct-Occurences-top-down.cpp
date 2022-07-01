// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    
    int mod = 1000000007;
    
    int subsequenceCount(string x, string y)
    {
      //Your code here
      int n = x.size();
      int m  = y.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      for(int i=0; i<m+1; i++)
      {
          dp[0][i] = 0;
      }
      for(int i=0; i<n+1; i++)
      {
          dp[i][0] = 1;
      }
      for(int i=1; i<n+1; i++)
      {
          for(int j=1; j<m+1; j++)
          {
              if(x[i-1] == y[j-1])
              {
                  dp[i][j] = ((dp[i-1][j-1])%mod + (dp[i-1][j])%mod)%mod;
              }
              else{
                  dp[i][j] = dp[i-1][j]%mod;
              }
          }
      }
      return dp[n][m];
    }
};
 


// { Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}  // } Driver Code Ends