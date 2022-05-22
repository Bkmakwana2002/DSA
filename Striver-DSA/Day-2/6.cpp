#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int n, int l, int mid, int r)
{
    int b[n];
    int i = l;
    int j = mid;
    int k = l;
    int count = 0;
    while (i <= mid-1 && j <= r)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            count = count + mid - i;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
    }
    return count;
}

int mergeSort(int arr[], int n, int l, int r)
{
    int mid, inv_count = 0;
    if (l < r)
    {
        mid = (l + r) / 2;
        inv_count = inv_count + mergeSort(arr, n, l, mid);
        inv_count = inv_count + mergeSort(arr, n, mid + 1, r);
        inv_count = inv_count + merge(arr, n, l, mid, r);
    }
    return inv_count;
}

int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    int ans = mergeSort(arr, n, 0, n - 1);
    cout << "The total inversions are " << ans << endl;
    return 0;
}