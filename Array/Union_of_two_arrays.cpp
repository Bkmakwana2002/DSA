#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;
    int arr[n1];
    for(int i=0; i<n1; i++)
    {
        cin>>arr[i];
    }
    int brr[n2];
    for(int i=0; i<n2; i++)
    {
        cin>>brr[i];
    }
    unordered_set <int> s;
    for(int i=0; i<n1; i++)
    {
        s.insert(arr[i]);
    }
    for(int i=0; i<n2; i++)
    {
        s.insert(brr[i]);
    }
    cout<<s.size();
    return 0;
}
