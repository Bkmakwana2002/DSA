#include <bits/stdc++.h>
using namespace std;

bool t[4][11];

vector<bool> subSetSum(int arr[],int sum, int n)
{
    for(int j=0; j<=sum; j++)
    {
        t[0][j] = false;
    }
    for(int i=0; i<=n; i++)
    {
        t[i][0] = true;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(j>=arr[i-1])
            {
                t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    vector<bool> v;
    for(int i=0;i<=sum; i++)
    {
        v.push_back(t[n][i]);
    }
    return v;
}

int min_sum(int arr[], int sum, int n)
{
    vector<bool> v = subSetSum(arr,sum,n);
    int min_ans = INT_MAX;
    for(int i=0; i<v.size()/2; i++)
    {
        if(v[i] == true)
        {
           min_ans = min(sum-2*i,min_ans);
        }
    }
    return min_ans;
}

int main()
{
    int n = 3;
    int arr[] = {1, 2, 7};
    int sum = 10;
    cout<<min_sum(arr,sum,n);
    return 0;
}