#include <bits/stdc++.h>
using namespace std;

int maxSum(int Arr[], int n)
{
    int max = 0;
    int curr = 0;
    for(int i=0; i<n; i++)
    {
        curr = curr + Arr[i];
        if(curr >= max)
        {
            max = curr;
        }
        if(curr<0)
        {
            curr = 0;
        }
    }
 return max;
}

int main()
{
    int n;
    cin>>n;
    int Arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>Arr[i];
    }
    cout<<maxSum(Arr,n);
    return 0;
}
