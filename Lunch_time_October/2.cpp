// Difference between the days required must be 1 or 0

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

bool ans(ll sum, ll cc)
{
    if(sum == cc)
    {
        return true;
    }
    else
   return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,p,q;
        cin>>a;
        cin>>b;
        cin>>p;
        cin>>q;
        if((p%a == 0) && (q%b == 0))
        {
            ll x1 = p/a;
            ll x2 = q/b;
            if(abs(x1-x2) == 0 || abs(x1-x2) == 1)
            {
                cout<<"YES";
            } 
            else{
                cout<<"NO";
            }
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}