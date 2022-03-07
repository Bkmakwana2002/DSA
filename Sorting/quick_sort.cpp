#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j],arr[l]);
    return j;
}

void quickSort(int arr[],int n,int l,int h)
{
    if(l<h)
    {
        int pivotPos = Partition(arr,l,h);
        quickSort(arr,n,l,pivotPos-1);
        quickSort(arr,n,pivotPos+1,n-1);
    }
}


int main()
{
    int arr[] = {4, 3, 1, 5, 7};
    int n = 5;
    quickSort(arr, n,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}