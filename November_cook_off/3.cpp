#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long int> v;
        for(long long int i=0; i<=2*n+1; i++)
        {
            if(i%2!=0)
            {
                v.push_back(i);
            }
        }
        for(long long int i=0; i<v.size()-1; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}