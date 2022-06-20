#include <bits/stdc++.h>
using namespace std;

bool t[7][31];

bool subSetSum(int sum, int arr[], int n)
{

    for (int i = 1; i < 31; i++)
    {
        t[0][i] = false;
    }
    for (int i = 0; i < 7; i++)
    {
        t[i][0] = true;
    }
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 31; j++)
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

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 30;
    int n = 6;
    cout << subSetSum(sum, arr, n);
    return 0;
}