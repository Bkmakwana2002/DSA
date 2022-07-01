#include <bits/stdc++.h>
using namespace std;

int t[6][11];

int countsubSetSum(int sum, int arr[], int n)
{
    for(int j=0 ; j<11; j++)
    {
       t[0][j] = 0;
    }
    t[0][0] = 1;
    for(int i=1; i<6; i++)
    {
        for(int j=0; j<11; j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 10;
    int n = 5;
    cout << countsubSetSum(sum, arr, n);
    return 0;
}