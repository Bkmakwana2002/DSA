#include <bits/stdc++.h>
using namespace std;

int ans(int m, int n)
{
    if(n==1 || m ==1)
    {
        return 1;
    }
    return ans(n-1,m)+ans(n,m-1);
}

int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    cout<<ans(n,m);
    return 0;
}