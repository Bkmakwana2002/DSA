// https://www.codechef.com/LTIME106C/problems/SALE2
#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        int ans = 0;
        if(n%3 == 0)
        {
            ans = (x*2)*n/3;
        }
        else{
            ans = (n/3)*2*x + (n-(2*(n/3))-n/3)*x;
        }
        cout<<ans<<endl;
    }
    return 0;
}