#include <bits/stdc++.h>
using namespace std;

bool t[5][23];

bool subSetSum(int arr[], int n,int sum)
{
  for (int i = 1; i < sum+1; i++)
    {
        t[0][i] = false;
    }
    for (int i = 0; i < n+1; i++)
    {
        t[i][0] = true;
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if (j < arr[i - 1])
            {
                t[i][j] = t[i - 1][j];
            }
            if (j >= arr[i - 1])
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
            }
        }
    }
    return t[n][sum];
}

bool equalSum(int arr[],int n, int sum)
{
    if(sum%2 != 0)
    {
        return false;
    }
    bool ans = subSetSum(arr,n,sum/2);
    return ans;
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = 4;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = sum + arr[i];
    }
    cout<<equalSum(arr,n,sum);
    return 0;
}