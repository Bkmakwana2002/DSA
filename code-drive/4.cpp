#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k,ans=0;
    string s;
    cin>>n>>k>>s;
    int xo=0;
    for(int i=0; i<n-k; i++)
    {
        xo^=(s[i]-'0');
    }
    if(xo==1) ans++;
    int indbeg = 0,indend=n-k+1;
    while(indend<n)
    {
        xo^=(s[indbeg++]-'0');
        xo^=(s[indend++]-'0');
        if(xo==1) ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
}
