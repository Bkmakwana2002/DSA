#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int rev = 0;
    int n;
    cin>>n;
    int temp = n;
    while(temp>0)
    {
        int rem = temp%10;
        temp = temp/10;
        rev = rev*10 + rem;
    }
    if(rev == n)
    {
        cout<<true;
        return;
    }
    cout<<false;
}

int main()
{
    solve();
    return 0;
}