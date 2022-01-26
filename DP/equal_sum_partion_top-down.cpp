#include <bits/stdc++.h>
using namespace std;

bool t[5][23];

bool subSetSum(int arr[], int n,int S)
{
   for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
            else if (j >= arr[i - 1])
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][S];
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