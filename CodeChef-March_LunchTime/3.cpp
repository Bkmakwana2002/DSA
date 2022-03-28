// https://www.codechef.com/LTIME106C/problems/SPLITPAIR
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

string checkEven(int n)
{
    while (n > 0)
    {
        if ((n % 10) % 2 == 0)
        {
            return "YES";
        }
        n = n / 10;
    }
    return "NO";
}

string checkOdd(int n)
{
    while (n > 0)
    {
        if ((n % 10) % 2 != 0)
        {
            return "YES";
        }
        n = n / 10;
    }
    return "NO";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if ((n % 10) % 2 == 0)
        {
            cout << checkEven(n / 10);
        }
        else
        {
            cout << checkOdd(n / 10);
        }
        cout << endl;
    }
    return 0;
}