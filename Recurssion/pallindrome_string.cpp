#include<bits/stdc++.h>
using namespace std;

bool string_pallindrom(string s,int l,int r)
{
    if(l>=r)
    {
        return true;
    }
    if(s[l]!=s[r])
    {
        return false;
    }
    return string_pallindrom(s,l+1,r-1);
}

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    cout<<string_pallindrom(s,0,n-1);
    return 0;
}