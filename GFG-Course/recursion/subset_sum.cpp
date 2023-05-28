#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int sum_subset(vector<int> v, int n, int sum)
{
    if(n==0)
    {
        return (sum == 0) ? 1 : 0;
    }
    return sum_subset(v,n-1,sum) + sum_subset(v,n-1,sum-v[n-1]);

}

void solve()
{ 
    int n;
    cin>>n;
    int sum ;
    cin>>sum;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    cout<<sum_subset(v,n,sum);
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