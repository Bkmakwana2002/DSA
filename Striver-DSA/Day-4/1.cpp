#include <bits/stdc++.h>
using namespace std;

vector<int> return_pair(int n, vector<int> v, int target)
{
    vector<int> pair;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++)
    {
        if(m.find(target-v[i])!=m.end())
        {
            pair.push_back(m[target-v[i]]);
            pair.push_back(i);
        }
        m[v[i]]=i;
    }
    return pair; 
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int target;
    cin>>target;
    vector<int> pair=return_pair(n,v,target);
    for(int i=0; i<pair.size(); i++)
    {
        cout<<pair[i]<<" ";
    }
    return 0;
}