#include <bits/stdc++.h>

using namespace std;

int getAns(vector<int> Arr, int ind, int buy, int n, vector<vector<int>> &dp ,int fees ){

    if(ind>=n) return 0; 
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    int profit;
    
    if(buy==0){
        profit = max(0+getAns(Arr,ind+1,0,n,dp,fees), -Arr[ind]+getAns(Arr,ind+1,1,n,dp,fees));
    }
    
    if(buy==1){
        profit = max(0+getAns(Arr,ind+1,1,n,dp,fees), Arr[ind]+getAns(Arr,ind+1,0,n,dp,fees)-fees);
    }
    
    return dp[ind][buy] = profit;
}


int stockProfit(vector<int> &Arr,int fees)
{
    int n = Arr.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    
    int ans = getAns(Arr,0,0,n,dp,fees);
    return ans;
}

int main() {

  vector<int> prices {4,9,0,4,10};
  int fees;
  cin>>fees;                                
  cout<<"The maximum profit that can be generated is "<<stockProfit(prices,fees);
}
