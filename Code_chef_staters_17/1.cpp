#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,z;
        cin>>x;
        cin>>y;
        cin>>z;
        if(z>=x+y)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}
