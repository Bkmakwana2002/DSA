#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int a[], int n, int target)
{
    for(int i=0; i<n ; i++)
    {
       if(a[i] == target)
       {
           return true;
       }
    }
    return false;
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
    cout<<linearSearch(a, n, target);
    return 0;
}