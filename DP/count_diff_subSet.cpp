#include <bits/stdc++.h>
using namespace std;

int t[5][5];

int count_diff(int arr[], int sum, int S, int diff, int n)
{
   for(int i=0; i<=S; i++)
   {
       t[0][i] = 0;
   }
   for(int i=0; i<=n; i++)
   {
       t[i][0] = 1;
   }
   for(int i=1; i<=n; i++)
   {
       for(int j=1; j<=S; j++)
       {
          if(j>=arr[i-1])
          {
              t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
          }
          else{
              t[i][j] = t[i-1][j];
          }
       }
   }
   return t[n][S];
}

int main()
{
    int arr[] = {1, 1, 2, 3};
    int n = 4;
    int sum = 7;
    int diff = 1;
    int S = (sum+diff)/2;
    cout<<count_diff(arr,sum,S,diff,n);
    return 0;
}