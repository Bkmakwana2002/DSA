#include <bits/stdc++.h>
using namespace std;

int ans(int arr[], int n, int k)
{
    sort(arr,arr+n);
        int min_num = arr[0];
        int max_num = arr[n-1];
        int res = max_num - min_num;
        for(int i=1; i<n; i++)
        {
            max_num = max(arr[n-1]-k,arr[i-1]+k);
            min_num = min(arr[i]-k,arr[0]+k);
            if(min_num<0)
            {
                continue;
            }
            else{
            res = min(res,max_num-min_num);
        }
        }
        return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>k;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
    cout<<ans(arr,n,k)<<endl;
    }
    return 0;
}