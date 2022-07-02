// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
  
 bool match(string pattern, string str, int i, int j,vector<vector<int>> &dp){
        if (i<0&&j<0) return 1;
        if(i<0&&j>=0) return 0;
        if(i>=0 && j<0){
            for (int x = 0; x<=i; x++){
                if(pattern[x]!='*') return false;
            }
            return true;
        }
        
        if (dp[i][j]!=-1) return dp[i][j];
        //its a match
        if(pattern[i]==str[j] || pattern[i]=='?') return dp[i][j] = match(pattern,str,i-1,j-1,dp);
        else if(pattern[i]=='*') return dp[i][j] = match(pattern,str,i-1,j,dp) | match(pattern,str,i,j-1,dp);
        
        return dp[i][j] = false;
    }
  
/*You are required to complete this method*/
     int wildCard(string pattern,string str)
    {
        vector<vector<int>> dp(pattern.size()+1, vector<int> (str.size()+1,-1));
        return match(pattern,str,pattern.size()-1,str.size()-1,dp);
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends