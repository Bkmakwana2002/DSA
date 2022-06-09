#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int facN = 1;
    for (int i = 2; i <= n; i++)
    {
        facN = i * facN;
    }
    return facN;
}

int nCr(int n, int i)
{
    return factorial(n) / (factorial(i) * factorial(n - i));
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans;
    for (int k = 1; k <= n; k++)
    {
        vector<int> arr;
        for (int i = 0; i <= k - 1; i++)
        {
            arr.push_back(nCr(k - 1, i));
        }
        ans.push_back(arr);
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }    
    return 0;
}