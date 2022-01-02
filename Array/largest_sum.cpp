#include <bits/stdc++.h>
using namespace std;

int ans(int arr[], int n)
{
    int currSum = 0;
    int maxSum = 0;
    for(int i=0; i<n; i++)
    {
        currSum = currSum +arr[i];
        maxSum = max(currSum,maxSum);
        if(currSum<0)
        {
            currSum = 0;
        }
    }
  return maxSum;
}

int main()
{   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<ans(arr,n);
    return 0;
}