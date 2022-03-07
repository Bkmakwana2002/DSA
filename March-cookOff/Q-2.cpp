#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      ll n;
      cin>>n;
      ll arr[n];
      for(ll i=0; i<n; i++)
      {
          cin>>arr[i];
      }
      ll countZero = 0;
      for(ll i=0; i<n; i++)
      {
          if(arr[i] == 0)
          {
              countZero++;
          }
      }
      cout<<max(countZero,n-countZero)<<endl;;
    }
    return 0;
}