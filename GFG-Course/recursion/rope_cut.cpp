#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int ropeCut(int n, int a, int b, int c)
{
    if(n == 0)
    {
        return  0;
    }
    if(n<0)
    {
        return -1;
    }
    int res = max(max(ropeCut(n-a,a,b,c),ropeCut(n-b,a,b,c)),ropeCut(n-c,a,b,c));
    if(res <0)
    {
        return -1;
    }
    return res+1;
}

void solve()
{ 
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    cout<<ropeCut(n,a,b,c);
}

int main()
{
	int t;
    cin>>t;
	while(t--)
	{
		solve();
		cout<<endl;
	}
	return 0;
}