#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num;
    cin>>num;
    int bitStatus = (num>>n)&1;
    cout<<bitStatus;
    return 0;
}