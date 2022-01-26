#include <bits/stdc++.h>
using namespace std;

int t[4][6];

int coinMax (int sum, int arr[], int n)
{
   for(int j=0; j<=sum; j++)
   {
       t[0][j] = 0;
   }
   for(int i=0; i<=n; i++)
   {
       t[i][0] = 1;
   }
   for(int i=1; i<=n; i++)
   {
       for(int j=1; j<=sum; j++)
       {
         if(j>=arr[i-1])
         {
            t[i][j] = t[i-1][j] + t[i][j-arr[i-1]];
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