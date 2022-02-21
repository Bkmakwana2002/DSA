#include <bits/stdc++.h>
using namespace std;

int sliding_window_max_sum(int arr[], int n, int k)
{
    int i=0;
    int j=0;
    int sum = 0;
    int mx = INT_MIN;
    while(j<n)
    {
        sum = sum + arr[j];
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
          mx = max(sum,mx);
          sum = sum-arr[i];
          i++;
          j++;  
        }
    }
    return mx;
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[] = {2,5,1,8,2,9,1};
    cout<<sliding_window_max_sum(arr,n,k);
    return 0;
}