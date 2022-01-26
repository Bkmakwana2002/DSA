#include <bits/stdc++.h>
using namespace std;

bool subSetSum(int arr[], int n,int S)
{
   if(S == 0)
   {
       return true;
   }
   if(n == 0)
   {
       return false;
   }
   else if(S>=arr[n-1])
   {
       return (subSetSum(arr,n-1,S-arr[n-1]) || subSetSum(arr,n-1,S));
   }
   return subSetSum(arr,n-1,S) ;
}

bool equalSum(int arr[],int n, int sum)
{
    if(sum%2 != 0)
    {
        return false;
    }
    bool ans = subSetSum(arr,n,sum/2);
    return ans;
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = 4;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = sum + arr[i];
    }
    cout<<equalSum(arr,n,sum);
    return 0;
}