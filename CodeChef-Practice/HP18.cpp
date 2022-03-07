// https://www.codechef.com/problems/HP18
#include <bits/stdc++.h>
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
      ll a,b;
      cin>>a>>b;
      ll arr[n];
      for(ll i=0; i<n; i++)
      {
          cin>>arr[i];
      }
      ll common = 0;
      ll bob = 0;
      ll alice = 0;
      for(ll i=0; i<n; i++)
      {
          if(arr[i]%a == 0 && arr[i]%b == 0)
          {
              common++;
          }
          else if(arr[i]%a == 0)
          {
              bob++;
          }
          else if(arr[i]%b == 0)
          {
              alice++;
          }
      }
      if(common>0)
      {
          bob++;
      }
      if(bob>alice)
      {
          cout<<"BOB"<<endl;
      }
      else
      {
          cout<<"ALICE"<<endl;
      }
    }
    return 0;
}
