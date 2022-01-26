#include <bits/stdc++.h>
using namespace std;

bool subSetSum(int sum, int arr[], int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    else if (sum >= arr[n - 1])
    {
        return (subSetSum(sum - arr[n - 1], arr, n - 1) || subSetSum(sum, arr, n - 1));
    }
    return subSetSum(sum, arr, n - 1);
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int n = 5;
    cout << subSetSum(sum, arr, n);
    return 0;
}