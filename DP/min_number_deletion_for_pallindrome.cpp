#include <bits/stdc++.h>
using namespace std;

int t[7][7];

int min_number_deletion(int n, string x,string y)
{
    for(int i=0; i<=n; i++)
    {
        t[i][0] = 0;
    }
    for(int j=0; j<=n; j++)
    {
        t[0][j] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i-1] == y[j-1])
            {
               t[i][j] = t[i-1][j-1] + 1;
            }
            else {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return n-t[n][n];
}

int main()
{
    string x = "agbcba";
    int n = x.length();
    string y = x;
    reverse(y.begin(),y.end());
    cout<<min_number_deletion(n,x,y);
    return 0;
}