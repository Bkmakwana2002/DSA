#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,p,q;
        cin>>a;
        cin>>b;
        cin>>p;
        cin>>q;
        int ans;
        if(a==p && b==q)
        {
            ans = 0;
        }
        else if(((a+b)%2 == 0 && (p+q)%2 != 0) || ((a+b)%2 != 0 && (p+q)%2 == 0))
        {
            ans = 1;
        }
        else
        {
            ans = 2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
