// https://www.codechef.com/LTIME106C/problems/MINCOINS
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        ll count = -1;
        cin >> n;
        if (n % 10 != 0 && n % 5 == 0)
        {
            count = n / 5 - n / 10;
        }
        else if (n % 10 == 0)
        {
            count = n / 10;
        }
        cout << count<< endl;
    }
    return 0;
}