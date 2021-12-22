#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int remainder;
    cin>>n;
    int t = n;
    int res = 0;
    while(t>0)
    {
      remainder = t%10;
      res = res*10 + remainder;
      t = t/10;
    }
    if(res == n)
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
