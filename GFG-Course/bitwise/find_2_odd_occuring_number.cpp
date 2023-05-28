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
    int res1=0, res2=0;
    int right_most_set_bit = res & ~(res-1);
    for(int i=0; i<n; i++)
    {
       if(arr[i] & right_most_set_bit)
       {
          res1 = res1 ^ arr[i];
       }
       else{
        res2 = res2^arr[i];
       }
    }
    cout<<res1<<" "<<res2;
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