#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int b[n] = {0};
    int temp = a[n-1];
    for(int i=n-1; i>=0; i--)
    {
       if(temp!=0 || a[i]!=0)
       {
         b[i] = 1;
         temp = max(temp,a[i]);
         temp--;
       }
       else{
           b[i] = 0;
       }
    }
    for(int i=0; i<n; i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}