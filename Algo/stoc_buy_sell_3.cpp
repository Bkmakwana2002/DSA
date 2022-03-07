#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    int profit = 0;
    vector<int>v;
    for (int i = 1; i < n; i++)
    {
        if (Arr[i]>Arr[i-1])
        {
            profit =  (Arr[i]-Arr[i-1]);
            v.push_back(profit);
        }
    }
    sort(v.begin(),v.end());
    int x = v.size();
    int ans = v[x-1]+v[x-2];

    int maxProfit = 0;
    int minSoFar = Arr[0];
    for(int i=0; i<n; i++)
    {
       minSoFar = min(minSoFar,Arr[i]);
       int profit = Arr[i] - minSoFar;
       maxProfit = max(maxProfit,profit);
    }
    cout<<max(ans,maxProfit);
}