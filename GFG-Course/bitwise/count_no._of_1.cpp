#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void brian_kernigam_algo()
{
    int n;
    cin>>n;
    int res = 0;
    while(n>0)
    {
        n = (n&(n-1));
        res ++ ;
    }
    cout<<res;
} 
  

void solve() // naive sol
{
    int n;
    cin>>n;
    int res= 0;
    while(n>0)
    {
        if((n%2 != 0) || ((n&1) == 1))
        {
            res ++ ;
        }
        n = n>>1;
    }
    cout<<res;
}

int main()
{
	int t;
    cin>>t;
	while(t--)
	{
		brian_kernigam_algo();
		cout<<endl;
	}
	return 0;
}