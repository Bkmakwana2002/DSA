#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{ 
    // number of set bits in a number who is the power of 2 is always 1
    int n;
    cin>>n;
    int res = 0;
    while(n>0)
    {
       n = n&(n-1);
       res++;
    }
    if(res == 1)
    {
       cout<<"YES";
       return;
    }
    cout<<"NO";
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