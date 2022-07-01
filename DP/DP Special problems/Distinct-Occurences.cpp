// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    
    int mod = 1000000007;
    
    int f(int i, int j, string x, string y, vector<vector<int>> &dp)
    {
        if(j<0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(x[i] == y[j])
        {
            return dp[i][j] = ((f(i-1,j,x,y,dp))%mod + (f(i-1,j-1,x,y,dp))%mod)%mod;
        }
        return dp[i][j] = f(i-1,j,x,y,dp)%mod;
    }
    
    int subsequenceCount(string S, string T)
    {
      //Your code here
      int n = S.size();
      int m  = T.size();
      vector<vector<int>> dp(n,vector<int>(m,-1));
      return f(n-1,m-1,S,T,dp);
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