//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void f(vector<string> &v,string &s, int close, int open)
    {
        if(close == 0 && open == 0)
        {
            v.push_back(s);
            return ;
        }
        if(open>0)
        {
            s.push_back('(');
            f(v,s,close,open-1);
            s.pop_back();
        }
        if(close>0 && open<close)
        {
           s.push_back(')');
           f(v,s,close-1,open);
           s.pop_back();
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> v;
        string s;
        f(v,s,n,n);
        return v;
    } 
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends