#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int n, int l, int mid, int r)
{
    int b[n];
    int i = l;
    int j = mid+1;
    int k = l;
    while (i <= mid && j <= r)
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
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= r)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = l; k <= r; k++)
    {
        arr[k] = b[k];
    }
}

void mergeSort(int arr[], int n, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, n, l, mid);
        mergeSort(arr, n, mid + 1, r);
        merge(arr, n, l, mid, r);
    }
}

int main()
{
    int arr[] = {4, 3, 1, 5, 7};
    int n = 5;
    int l = 0;
    int r = n - 1;
    mergeSort(arr, n, l, r);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}