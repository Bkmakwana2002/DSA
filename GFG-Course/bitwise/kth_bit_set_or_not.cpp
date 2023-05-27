#include<bits/stdc++.h>
using namespace std;
#define ll long long int


/**
 * Solves the given problem by checking if the kth bit of n is set or not.
 * @param n integer input from user
 * @param k integer input from user
 * @return 1 if the kth bit of n is set, 0 otherwise
 */
void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    if(n & (1<<(k-1)) != 0)
    {
        cout<<"1";
    }
    else{
        cout<<"0";
    }
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