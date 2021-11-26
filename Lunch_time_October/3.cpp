// 1+2+3+4+.......+pow(2,n-1) = pow(2,n)-1; 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<1<<" "<<1<<" ";
    for(int i=1; i<n; i++)
    {
      cout<<pow(2,i)<<" ";
    }
    return 0;
}