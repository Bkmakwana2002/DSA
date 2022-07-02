// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int f(int index, int buy ,int n, int cap, int arr[], vector<vector<vector<int>>> &dp)
    {
        if(index == n || cap == 0)
        {
            return 0;
        }
        if(dp[index][buy][cap] != -1)
        {
            return dp[index][buy][cap];
        }
        int profit;
        if(buy == 1)
        {
            profit = max(f(index+1,0,n,cap,arr,dp)-arr[index],f(index+1,1,n,cap,arr,dp));
        }
        else{
            profit = max(f(index+1,1,n,cap-1,arr,dp)+arr[index],f(index+1,0,n,cap,arr,dp));
        }
        return  dp[index][buy][cap] = profit;    
        
    }

    int maxProfit(int K, int N, int A[]) {
        // code here
         vector<vector<vector<int>>> dp(N,
                                    vector<vector<int>> 
                                            (2,vector<int>(K+1,-1)));
        return f(0,1,N,K,A,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends