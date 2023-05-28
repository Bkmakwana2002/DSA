#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int josephus(int n, int k)
{
    if(n==1)
    {
        return 0    ;
    }
    return (josephus(n-1,k)+k)%n;
}

void solve()
{ 
    int n,k;
    cin>>n>>k;
    cout<<josephus(n,k);
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