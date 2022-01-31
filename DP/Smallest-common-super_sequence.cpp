#include <bits/stdc++.h>
using namespace std;

int t[6][7];

int ans(int n, int m, string x, string y)
{
    for(int i=0; i<=n; i++)
    {
        t[i][0] = 0;
    }
    for(int j=0; j<=m; j++)
    {
        t[0][j] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(x[i-1] == y[j-1])
            {
                t[i][j] = t[i-1][j-1] + 1;
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return (n+m-t[n][m]);
}

int main()
{
    string x = "acbef";
    string y = "abcdaf";
    int n = x.length();
    int m = y.length();
    cout<<ans(n,m,x,y);
    return 0;
}