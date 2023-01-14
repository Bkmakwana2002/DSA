#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(int arr[], int n)
{
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i=0; i<n; i++)
    {
        if(!s.empty() && arr[s.top()] < arr[i])
        {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v = nextGreaterElement(arr, n);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}