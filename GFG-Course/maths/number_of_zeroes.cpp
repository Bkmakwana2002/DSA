#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n;
    cin>>n;
    int res = 0;
    for(int i=5; i<=n; i=i*5)
    {
        res = res + n/i;
    }
    cout<<res;
}

int main()
{
    solve();
    return 0;
}