#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a;
        cin>>b;
        if((a+b)%2 == 0)
        {
            cout<<"Bob";
        }
        else
        {
            cout<<"Alice";
        }
        cout<<endl;
    }
    return 0;
}
