#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin >> n;
    if(n == 0)
    {
       cout<<1;
       return -1;
    }
    cout<<floor(log10(n)+1);
    return 0;
}