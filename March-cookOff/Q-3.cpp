#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll x;
        cin >> x;
        bool flag = false;
        for (ll i = 1; i <= n; i++)
        {
            flag = flag | ((x%i==0)&&(x/i<=n-i+1));
        }
        if (flag)
        {
            cout << "YES";
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }

    return 0;
}