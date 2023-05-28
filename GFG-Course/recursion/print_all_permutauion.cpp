#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void printString(string s, int i=0)
{
    if(i==s.size()-1)
    {
        cout<<s<<" ";
    }
    for(int j=i; j<s.size(); j++)
    {
        swap(s[i],s[j]);
        printString(s,i+1);
        swap(s[j],s[i]);
    }
}

void solve()
{ 
    string s;
    cin>>s;
    printString(s);
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