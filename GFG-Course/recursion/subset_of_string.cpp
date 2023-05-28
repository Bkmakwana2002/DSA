#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void powerSet(string str, int index = 0, string curr = "")
{
    int n = str.length();
    if (index == n) {
        cout << curr << endl;
        return;
    }
    powerSet(str, index + 1, curr + str[index]);
    powerSet(str, index + 1, curr);
}

void solve()
{ 
    string s;
    cin>>s;
    int n = s.size();
    powerSet(s);
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