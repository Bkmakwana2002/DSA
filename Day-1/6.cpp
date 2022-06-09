#include <bits/stdc++.h>
using namespace std;

int ans(int Arr[], int n)
{
    int maxProfit = 0;
    int minSoFar = Arr[0];
    for(int i=0; i<n; i++)
    {
       minSoFar = min(minSoFar,Arr[i]);
       int profit = Arr[i] - minSoFar;
       maxProfit = max(maxProfit,profit);
    }
    return maxProfit;
}

int main()
{
    int n;
    cin>>n;
    int Arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>Arr[i];
    }
    cout<<ans(Arr,n);
    return 0;
}