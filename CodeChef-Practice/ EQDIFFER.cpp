// https://www.codechef.com/problems/EQDIFFER
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
        ll arr[n];
        unordered_map<ll, ll> m;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        ll countMax = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            countMax = max(countMax, it->second);
        }
        if (n == 0 || n == 1 || n == 2)
        {
            cout << 0 << endl;
            ;
        }
        else
        {
            if (countMax == 1)
            {
                cout << n - 2 << endl;
            }
            else
            {
                cout << n - countMax << endl;
            }
        }
    }
    return 0;
}
