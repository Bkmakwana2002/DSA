#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{ 
    int n;
    cin>>n;
    string s;
    cin>>s;
    int power_set = pow(2,n);
    for(int i=0; i<power_set; i++)
    {
        for(int j=0; j<n; j++)
         {
            if(i & (1<<j))
              {
                cout<<s[j];
              }
         }
         cout<<endl;
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