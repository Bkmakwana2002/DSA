#include <bits/stdc++.h>
using namespace std;

int t[4][6];

int coinMax (int sum, int arr[], int n)
{
   for(int i=1; i<=n; i++)
   {
       t[i][0] = 0;
   }
   for(int j=0; j<=sum;j++)
   {
       t[0][j] = INT_MAX-1;
   }
   for(int j=1; j<=sum; j++)
   {
       if(j%arr[0] == 0)
       {
           t[1][j] = j/arr[0];
       }
       else{
           t[1][j] = INT_MAX-1;
       }
   }
   for(int i=2; i<=n; i++)
   {
       for(int j=1; j<=sum; j++)
       {
           if(j>=arr[i-1])
           {
               t[i][j] = min(t[i-1][j],t[i][j-arr[i-1]]+1);
           }
           else{
               t[i][j] = t[i-1][j];
           }
       }
   }
   return t[n][sum];
}

int main()
{
    int arr[] = {1, 2, 3,};
    int sum = 5;
    int n = 3;
    cout<<coinMax(sum,arr,n);
    return 0;
}