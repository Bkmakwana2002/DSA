#include<bits/stdc++.h>
using namespace std;

int josh(int n, int k)
{
    if(n==1)
    {
        return 0;
    }
    return (josh(n-1,k)+k)%n;
}

int main()
{
    int n;
    int k;
    cin>>n;
    cin>>k;
    cout<<josh(n,k);
    return 0;
}
