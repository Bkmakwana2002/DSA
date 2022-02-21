#include <bits/stdc++.h>
using namespace std;

void reArrange(int arr[], int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while(i<n && arr[i]>0)
        {
           i++;
        }
        while(j>=0 && arr[j]<0)
        {
           j--;
        }
        if(i<j)
        {
        swap(arr[i],arr[j]);
        }
    }
    for(int k=0; k<n; k+2)
    {
       swap(arr[i],arr[k]);
       i++;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    reArrange(arr,n);
    return 0;
}
