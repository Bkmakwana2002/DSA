// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
      stack<int> st1;
      stack<int> st2;
      vector<int> ls(n,0);
      vector<int> rs(n,0);
      for(int i=n-1; i>=0; i--)
      {
          while(!st1.empty() && st1.top()>=A[i])
          {
              st1.pop();
          }
          if(i<n)
          {
              if(!st1.empty())
              {
                  rs[i] = st1.top();
              }
          }
          st1.push(A[i]);
      }
      for(int i=0; i<n; i++)
      {
          while(!st2.empty() && st2.top()>=A[i])
          {
              st2.pop();
          }
          if(i<n)
          {
              if(!st2.empty())
              {
                  ls[i] = st2.top();
              }
          }
          st2.push(A[i]);
      }
      vector<int> diff(n);
      for(int i=0; i<n; i++)
      {
          diff[i] = abs(ls[i]-rs[i]);
      }
      int maxDiff = INT_MIN;
      for(int i=0; i<n; i++)
      {
          maxDiff = max(maxDiff,diff[i]);
      }
      return maxDiff;
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}


  // } Driver Code Ends