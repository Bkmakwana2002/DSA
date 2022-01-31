#include <bits/stdc++.h>
using namespace std;

int t[6][7];

string print_LCS(string x, string y, int n, int m)
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
            else {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    string s;
    int i = n;
    int j = m;
    while(i>=0)
    {
        while(j>=0)
        {
            if(x[i-1] == y[j-1])
            {
                s.push_back(x[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i][j-1]>t[i-1][j])
                {
                    j--;
                }
                else{
                    i--;
                }
            }
        }
    }
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    string x = "acbef";
    string y = "abcdaf";
    int n = x.length();
    int m = y.length();
    cout<<print_LCS(x,y,n,m);
    return 0;
}