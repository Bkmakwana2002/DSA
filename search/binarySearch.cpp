#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int n, int target, int l, int r)
{
   if(l<r)
   {
       int mid = (l+r)/2;
       if(a[mid] == target)
       {
           return mid;
       }
       else if(a[mid]>target)
       {
           return binarySearch(a, n, target, l, mid-1);
       }
       else
       {
           return binarySearch(a, n, target, mid+1, r);
       }
   } 
   return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int target;
    cin>>target;
    cout<<binarySearch(a, n, target, 0,n-1);
    return 0;
}