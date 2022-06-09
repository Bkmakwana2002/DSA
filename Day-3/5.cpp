#include <bits/stdc++.h> 
using namespace std;

int answer(int m,int n, int i, int j)
{
	if(i>=m || j>=n)
	{
		return 0;
	}
	else if(i==m-1 && j==n-1)
	{
		return 1;
	}
    return answer(m,n,i+1,j)+answer(m,n,i,j+1);
}

int uniquePaths(int m, int n) {
	return answer(m,n,0,0);
}

int main()
{
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n);
    return 0;
}
