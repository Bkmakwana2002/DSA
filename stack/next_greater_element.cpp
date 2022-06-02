#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(int arr[], int n)
{
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i=n-1; i>=0; i--)
    {
        while(!s.empty() && s.top()<=arr[i])
        {
            s.pop();
        }
        if(i<n)
        {
            if(!s.empty())
            {
                ans[i] = s.top();
            }
        }
        s.push(arr[i]);
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