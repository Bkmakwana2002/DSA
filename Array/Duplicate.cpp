#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;  
    int Arr[n+1];
    for(int i=0; i<n; i++)
    {
        cin>>Arr[i];
    }
    unordered_map <int,int> m;
    for(int i=0; i<n; i++)
    {
        m[Arr[i]]++;
    }
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        if(it->second == 2)
        {
            cout<<it->first;
        }
    }
    return 0;
}