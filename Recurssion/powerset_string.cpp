#include<bits/stdc++.h>
using namespace std;

void str_return(string s,int index = 0,string curr="")
{
    int n = s.length();
    if(index == n)
    {
        cout<<curr<<endl;
        return;
    }
    str_return(s,index+1,curr+s[index]);
    str_return(s,index+1,curr);
}

int main()
{
    string s;
    cin>>s;
    str_return(s);
    return 0;
}