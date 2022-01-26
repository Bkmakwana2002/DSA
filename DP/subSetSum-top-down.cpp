#include <bits/stdc++.h>
using namespace std;

bool t[6][12];

bool subSetSum(int sum, int arr[], int n)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 12; j++)
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
    return t[n][sum];
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int n = 5;
    cout << subSetSum(sum, arr, n);
    return 0;
}