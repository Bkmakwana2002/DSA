#include <bits/stdc++.h>
using namespace std;

int pairCount(int n, int k, int arr[])
{
    int count = 0;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++)
    {
        count = count + m[k-arr[i]];
        m[arr[i]]++;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[] = {1,5,7,1};
    cout<<pairCount(n,k,arr);
    return 0;
}