#include <bits/stdc++.h>
using namespace std;

int maxMeeting(int start[], int end[], int n)
{
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++)
    {
        v.push_back({end[i],start[i]});
    }
    sort(v.begin(),v.end());
    int meet = 1;
    int startMeet = v[0].second;
    int endMeet = v[0].first;
    for(int i=1; i<n; i++)
    {
        if(v[i].first>endMeet)
        {
            meet++;
            startMeet = v[i].second;
            endMeet  = v[i].first;
        }
    }
    return meet;
}

int main()
{
    int n;
    cin>>n;
    int start[n];
    int end[n];
    for(int i=0; i<n; i++)
    {
        cin>>start[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>end[i];
    }
    return 0;
}