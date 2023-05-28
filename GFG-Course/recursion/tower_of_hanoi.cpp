#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void tower_of_hanoi(int n, char A, char B, char C)
{
   if(n == 1)
   {
      cout<<"Move 1 from "<<A<<"to"<<C<<endl;
      return;
   }
   tower_of_hanoi(n-1,A,C,B);
   cout<<"Move"<<" "<<n<<" "<<"from"<<" "<<A<<"to"<<C<<endl;
   tower_of_hanoi(n-1,B,A,C);
}

void solve()
{ 
    char A,B,C;
    A = 'A';
    B = 'B';
    C = 'C';
    int n;
    cin>>n;
    tower_of_hanoi(n,A,B,C);
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