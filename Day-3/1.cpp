#include <bits/stdc++.h> 
using namespace std;

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int j = 0;
	int i = m-1;
	while(j<n && i>=0)
	{
		if(mat[i][j]>target)
		{
			i--;
		}
		else if(mat[i][j]<target)
		{
			j++;
		}
		else{
			return true;
		}
	}
	return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        vector < vector < int >> mat(m,vector < int > (n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
            }
        }
        int target;
        cin>>target;
        if(findTargetInMatrix(mat,m,n,target))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}