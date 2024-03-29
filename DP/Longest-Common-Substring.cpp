#include <bits/stdc++.h>
using namespace std;

int t[6][6];

int result = 0;

int LCS(string x, string y, int n, int m)
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
                t[i][j] = t[i-1][j-1] +1;
                result = max(result,t[i][j]);
            }
            else{
                t[i][j] = 0;
            }
        }
    }
    return result;
}

int main()
{
    string x = "abcde";
    string y = "abfce";
    int n = x.length();
    int m = y.length();
    cout << LCS(x, y, n, m);
    return 0;
}