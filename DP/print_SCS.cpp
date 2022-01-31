#include <bits/stdc++.h>
using namespace std;

int t[6][7];

string print_SCS(string x, string y, int n, int m)
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

    string s="";
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
                    s.push_back(y[j]);
                    j--;
                }
                else{
                    s.push_back(x[i]);
                    i--;
                }
            }
        }
    }
    while(i>0)
    {
       s.push_back(x[i-1]);
       i--;
    }
    while(j>0)
    {
        s.push_back(y[j-1]);
        j--;
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
    cout<<print_SCS(x,y,n,m);
    return 0;
}