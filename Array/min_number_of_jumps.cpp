#include <bits/stdc++.h>
using namespace std;

int min_jumps(int n, int arr[])
{
    int maxR = arr[0];
    int step = arr[0];
    int jump = 0;
    if(n==0)
    {
        return 0;
    }
    else if(arr[0] == 0)
    {
        return 0;
    }
    else
    {
       for(int i=1; i<n; i++)
       {
           if(i == n-1)
           {
               return jump;
           }
           maxR = max(maxR,i+arr[i]);
           step--;
           if(step == 0)
           {
               jump++;
               if(maxR < i)
               {
                   return -1;
               }
               step = maxR-i;
           }
       }
    }
    return jump;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<min_jumps(n,arr);
    return 0;
}