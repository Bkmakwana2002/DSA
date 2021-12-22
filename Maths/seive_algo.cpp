#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    bool hash[n+1];
    memset(hash,true,sizeof(hash));
    for(int i=0; i<n+1; i++)
    {
        arr[i] = i;
    }
    for(int i = 2; i*i<=n; i++)
    {
        for(int j=2*i; j<=n; j=j+i)
        {
            hash[j] = false;
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(hash[i] == true)
        {
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}