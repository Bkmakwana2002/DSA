#include <bits/stdc++.h>
using namespace std;

int countsubSetSum(int sum, int arr[], int n, int count, int index)
{
    if (index == n)
    {
        if (sum == 0)
        {
            count++;
        }
        return count;
    }
    count = countsubSetSum(sum - arr[index], arr, n, count, index + 1);
    count = countsubSetSum(sum, arr, n, count, index + 1);
    return count;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 10;
    int n = 5;
    int count = 0;
    cout << countsubSetSum(sum, arr, n, count, 0);
    return 0;
}