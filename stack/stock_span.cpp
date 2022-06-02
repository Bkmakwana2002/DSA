#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(int arr[], int n)
{
    vector<int> ans(n,-1);
    stack<pair<int,int>> s;
    for(int i=0; i<n; i++)
    {
        while(!s.empty() && s.top().first<=arr[i])
        {
            s.pop();
        }
        if(i<n)
        {
            if(!s.empty())
            {
                ans[i] = s.top().second;
            }
        }
        s.push({arr[i],i});
    }
    for(int i=0; i<n; i++)
    {
        ans[i] = i-ans[i];
    }
    return ans;
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v = stockSpan(arr, n);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}