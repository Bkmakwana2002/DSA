#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>>& tri, int n){
	
    int t[n][n];
    for(int i=n-1; i>=0; i--)
    {
        for(int j =i; j>=0; j-- )
        {
            if(i == n-1)
            {
                t[i][j] = tri[i][j];
            }
            else{
                int up = INT_MAX;
                int diag = INT_MAX;
                if(i>=0 && j>=0)
                {
                    up = t[i+1][j] + tri[i][j];
                    diag = t[i+1][j+1] + tri[i][j];
                    t[i][j] = min(up,diag);
                }
            }
        }
    }
    return t[0][0];
    
}

int main()
{
     int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int i = 0; i < m; i++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }
        cout << minimumPathSum(v,n) << endl;
    }
    return 0;
    return 0;
}