#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int res = 0;
    for(int i=0; i<n; i++)
    {
        res = res^arr[i];
    }
    for(int i=1; i<=n+1; i++)
    {
       res = res^i;
    }
    cout<<res;
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