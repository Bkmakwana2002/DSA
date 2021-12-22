#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    int left[n];
    left[0] = Arr[0];
    int right[n];
    right[n-1] = Arr[n-1]; 
    for(int i=1; i<n; i++)
    {
       left[i] = max(Arr[i],left[i-1]);
    }
    for(int i=n-2; i>=0; i--)
    {
       right[i] = max(Arr[i],right[i+1]);
    }
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = ans + (min(left[i],right[i])-Arr[i]);
    }
    cout<<ans;
    return 0;
}