#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int a, b;
    cin >> a >> b;
    int minNum = min(a, b);
    while (minNum > 0)
    {
        if (a % minNum == 0 && b % minNum == 0)
        {
            break;
        }
        minNum--;
    }
    cout << minNum;
}

int euclidian_algo()
{
    int x, y;
    cin >> x >> y;
    int a = min(x,y);
    int b = max(x,y);
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
        return a;
    }
    return a;
}

int euclidian_algo_optimized(int x,int y)
{
    if(y == 0)
    {
        return x;
    }
    return euclidian_algo_optimized(y,x%y);
}

int main()
{
    // solve();
    // cout << endl;
    cout<<euclidian_algo();
    return 0;
}