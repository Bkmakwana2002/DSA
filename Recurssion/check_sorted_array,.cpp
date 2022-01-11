#include <bits/stdc++.h>
using namespace std;

bool check_sorting(int arr[], int n, int index)
{
    if(index>=n)
    {
        return true;
    }
    if(arr[index]<=arr[index-1])
       { return false;}
    return check_sorting(arr,n,index+1);
}

int main()
{
    int n;
    cin>>n;
    int index = 1;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<check_sorting(arr,n,index);
    return 0;
}